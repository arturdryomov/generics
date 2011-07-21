import discogs_client as discogs
import urllib
import mimetypes
import sys
import os
from mutagen import id3, mp3

def get_track_info(track_filename):
  print(":: Getting track information")
  track = mp3.MP3(track_filename)
  # God bless dictions
  return {"artist": track["TPE1"].text, "album": track["TALB"].text}

def get_cover_url(song_info):
  print(":: Say hello to Discogs")
  # Sooo god damn
  artist = "".join(song_info["artist"])
  album = "".join(song_info["album"])
  # API is pretty nice, but should parse everything
  discogs.user_agent = "TestApp/0.1"
  artist = discogs.Artist(artist)
  for release in artist.releases:
    if release.title == album:
      images = release.data["images"]
      max_image = images[0]
      for image in images:
        if image["width"] > max_image["width"]:
          max_image = image
      return max_image["uri"]
  return "ERROR"

def download_cover(link):
  print(":: Downloading cover art")
  # Separate function or not, separate or not
  return urllib.urlretrieve(link)

def write_cover(mp3_filename, cover_filename):
  print(":: Writing cover to file")
  # Open files
  file = mp3.MP3(mp3_filename)
  image = open(cover_filename, "rb")
  
  # Get mime type of cover
  mimetypes.init()
  mime = mimetypes.guess_type(cover_filename)

  # Write cover to file
  file.tags.add(id3.APIC(encoding=3, mime=mime[0], type=3, data=image.read()))
  file.save(v1=2)
  image.close()

def fill_covers(path):
  for filename in os.listdir(path):
    file_path = os.path.join(path, filename)
    if os.path.isfile(file_path):
      mimetypes.init()
      if mimetypes.guess_type(file_path) == mimetypes.guess_type("f.mp3"):
        print(file_path)
        track_info = get_track_info(file_path)
        url = get_cover_url(track_info)
        if url == "ERROR":
          continue
        cover_filename = download_cover(url)
        write_cover(file_path, cover_filename[0])

  
if __name__ == "__main__":
  if len(sys.argv) > 1:
    fill_covers(sys.argv[1])
  else:
    print("Input is not specified")
