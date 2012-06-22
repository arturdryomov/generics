CXX = clang++
LD = $(CXX)

COMMON_FLAGS = -fcolor-diagnostics
RELEASE_FLAGS = -O2 $(COMMON_FLAGS)
DEBUG_FLAGS = -g -Wall $(COMMON_FLAGS)
EXTRA_DEBUG_FLAGS = $(DEBUG_FLAGS) \
	-pedantic \
	-Wextra \
	-Wconversion \
	-Wshadow \
	-Wfloat-equal \
	-Wswitch-default \
	-Wunreachable-code \
	-Winit-self


BINARY_NAME = app
OBJECTS_DIRECTORY = objects

source = $(wildcard *.cpp)
objects = $(patsubst %.cpp, $(OBJECTS_DIRECTORY)/%.o, $(source))


all:
	make release

prepare:
	@mkdir -p $(OBJECTS_DIRECTORY)

clean:
	@rm -rf $(OBJECTS_DIRECTORY) $(BINARY_NAME)


release: CCX_FLAGS = $(RELEASE_FLAGS)
release: prepare build

debug: CCX_FLAGS = $(DEBUG_FLAGS)
debug: prepare build

extra_debug: CCX_FLAGS = $(EXTRA_DEBUG_FLAGS)
extra_debug: prepare build


build: $(objects)
	$(LD) $(CCX_FLAGS) $(objects) -o $(BINARY_NAME)

$(objects): $(OBJECTS_DIRECTORY)/%.o: %.cpp
	$(CXX) $(CCX_FLAGS) $< -c -o $@
