TEX_BUILDER = xelatex
TEX_BUILDER_FLAGS = --shell-escape

DOCUMENT_BUILDER = latexmk
DOCUMENT_BUILDER_FLAGS = \
	-pdf \
	-pdflatex="$(TEX_BUILDER) $(TEX_BUILDER_FLAGS)"

MAIN_DOCUMENT_FILENAME = report


all:
	$(DOCUMENT_BUILDER) $(DOCUMENT_BUILDER_FLAGS) $(MAIN_DOCUMENT_FILENAME).tex

preview:
	$(DOCUMENT_BUILDER) $(DOCUMENT_BUILDER_FLAGS) -pvc $(MAIN_DOCUMENT_FILENAME).tex

clean:
	$(DOCUMENT_BUILDER) -C
	make clean-minted
	make clean-biblatex

clean-minted:
	rm -f $(MAIN_DOCUMENT_FILENAME).pyg

clean-biblatex:
	rm -f $(MAIN_DOCUMENT_FILENAME).run.xml
	rm -f $(MAIN_DOCUMENT_FILENAME).bbl
