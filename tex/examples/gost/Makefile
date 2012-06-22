TEX_BUILDER = xelatex
TEX_BUILDER_FLAGS = --shell-escape

DOCUMENT_BUILDER = latexmk
DOCUMENT_BUILDER_FLAGS = \
	-pdf \
	-pdflatex="$(TEX_BUILDER) $(TEX_BUILDER_FLAGS)"

MAIN_DOCUMENT_FILENAME = report


all:
	make -C title
	$(DOCUMENT_BUILDER) $(DOCUMENT_BUILDER_FLAGS) $(MAIN_DOCUMENT_FILENAME).tex

preview:
	make -C title
	$(DOCUMENT_BUILDER) $(DOCUMENT_BUILDER_FLAGS) -pvc $(MAIN_DOCUMENT_FILENAME).tex

clean:
	make -C title clean
	$(DOCUMENT_BUILDER) -C
	make clean-minted
	make clean-bibtex

clean-minted:
	rm -f $(MAIN_DOCUMENT_FILENAME).pyg

clean-bibtex:
	rm -f $(MAIN_DOCUMENT_FILENAME).bbl
	rm -f $(MAIN_DOCUMENT_FILENAME).blg
