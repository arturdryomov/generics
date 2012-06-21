DIAGRAM_GENERATOR = plantuml
DIAGRAM_GENERATOR_FLAGS = -tsvg -config plantuml.config

PAGE_GENERATOR = inkscape
PAGE_GENERATOR_FLAGS = --export-area-drawing

diagrams = $(wildcard *.puml)
images = $(patsubst %.puml, %.svg, $(diagrams))
pages = $(patsubst %.svg, %.pdf, $(images))


all:
	make generate_images

generate_images: $(images)

pdf:
	make generate_images
	make generate_pages

generate_pages: $(pages)

clean:
	rm -f $(images)	$(pages)


$(images): %.svg: %.puml
	$(DIAGRAM_GENERATOR) $(DIAGRAM_GENERATOR_FLAGS) $<

$(pages): %.pdf: %.svg
	$(PAGE_GENERATOR) $(PAGE_GENERATOR_FLAGS) $< --export-pdf=$@
