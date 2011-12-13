# For currect building you need to install some packages.
# Arch Linux:
#  texlive-core
#  texlive-langcyrillic
#  texlive-latexextra
#  xelatex-stuff (AUR)
#  ttf-droid
#  ttf-linux-libertine
#  ttf-paratype (AUR)
#  python-pygments
# Also you need Asana Math font for formulas. You could 
# download it yourself or get very huge texlive-fontsextra 
# package, which contains this font and many others.
# Build with make twice for currect table of contents.

CC = xelatex

MAIN_FILENAME = title

all:
	$(CC) $(MAIN_FILENAME).tex

clean:
	@rm -f $(MAIN_FILENAME).aux $(MAIN_FILENAME).log
	@rm -f $(MAIN_FILENAME).out $(MAIN_FILENAME).pdf
	@rm -f $(MAIN_FILENAME).toc
