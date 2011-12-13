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
BIB_CC = bibtex
CC_FLAGS = -shell-escape

MAIN_FILENAME = report

all:
	@make -C title
	$(CC) $(CC_FLAGS) $(MAIN_FILENAME).tex
	$(BIB_CC) $(MAIN_FILENAME).aux
	$(CC) $(CC_FLAGS) $(MAIN_FILENAME).tex

clean:
	@make -C title clean
	@rm -f $(MAIN_FILENAME).aux $(MAIN_FILENAME).log
	@rm -f $(MAIN_FILENAME).out $(MAIN_FILENAME).pdf
	@rm -f $(MAIN_FILENAME).toc $(MAIN_FILENAME).pyg
	@rm -f $(MAIN_FILENAME).bbl $(MAIN_FILENAME).blg
