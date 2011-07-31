import discogs_client as discogs
import os
import urllib2
import mimetypes
import sys
from mutagen import mp3, id3

discogs.user_agent = "TestApp/0.1"

def get_cover_url(track_info):
  """ Gets URL to cover art.
  Returns: Discogs URL to cover art image if exists, in other
  cases returns None value.
  Input: song info diction with "artist" and "album" fields."""

  # Make normal strings
  artist_name = "".join(track_info["artist"])
  release_title = "".join(track_info["album"])

  artist = discogs.Artist(artist_name)
  # reduce() or filter() would be better in other cases
  for release in artist.releases:
    if release.title == release_title:
      images = release.data["images"]
      cover = max(images, key=lambda image: image["width"])
      return cover["uri"]
  return None

def download_cover(cover_url):
  """ Downloads cover file. 
  Returns: image file contents.
  Input: Discogs cover URL """

  request = urllib2.Request(cover_url)
  # API requires it, but sometimes doesn't work
  request.add_header("User-Agent", discogs.user_agent)
  cover_file = urllib2.urlopen(request)
  return cover_file.read()

def get_track_info(track_filename):
  """ Gets information from MP3 tags.
  Returns: diction with "artist" and "album" fields.
  Input: filename of source track."""

  track = mp3.MP3(track_filename)
  return {"artist": track["TPE1"].text, "album": track["TALB"].text}

def write_cover(mp3_filename, cover_file):
  """ Writes cover image as tag to MP3 file.
  Returns: nothing.
  Input: MP3 filename, image contents."""

  file = mp3.MP3(mp3_filename)
  # Get mime type of cover
  mimetypes.init()
  mime = mimetypes.guess_type("f.jpeg")
  # Write cover as tag
  file.tags.add(id3.APIC(encoding=3, mime=mime[0], type=3, data=cover_file))
  file.save(v1=2)

def fill_covers(path):
  """ Fills cover tags in folder with MP3 files.
  Returns: nothing.
  Input: path to directory with MP3 files. """

  # Check path
  if not os.path.exists(path):
    print("Error: Path does not exists")
    return

  cover_file = False
  for filename in os.listdir(path):
    file_path = os.path.join(path, filename)
    if os.path.isfile(file_path):
      mimetypes.init()
      if mimetypes.guess_type(file_path) == mimetypes.guess_type("f.mp3"):
        print(file_path)
        print(":: Getting file information")
        track_info = get_track_info(file_path)
        # On first iteration download file
        if not cover_file:
          print(":: Downloading cover art")
          cover_url = get_cover_url(track_info)
          if cover_url is None:
            print("Sorry, no cover for such album")
            sys.exit()
          cover_file = download_cover(cover_url)
        print(":: Writing cover to file")
        write_cover(file_path, cover_file)

if __name__ == "__main__":
  if len(sys.argv) > 1:
    fill_covers(sys.argv[1])
  else:
    print("Error: Input is not specified")

