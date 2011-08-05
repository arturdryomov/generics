# Compiler and linker
CC = clang++
LD = $(CC)

# Flags of compiler
RELEASE_FLAGS = -O2 -Wall
DEBUG_FLAGS = -g -Wall 
EXTRA_DEBUG_FLAGS = $(DEBUG_FLAGS) \
	-pedantic \
	-Wextra \
	-Wconversion \
	-Wshadow \
	-Wfloat-equal \
	-Wswitch-default \
	-Wunreachable-code \
	-Winit-self

# Output binary name
BINARY_NAME = app

# Directory of object files
OBJ_DIR = objects

# Names of object files
objects = $(OBJ_DIR)/cool.o $(OBJ_DIR)/main.o

# Targets
all:
	make release

prepare:
	@mkdir -p $(OBJ_DIR)


release: CC_FLAGS = $(RELEASE_FLAGS)
release: prepare build

debug: CC_FLAGS = $(DEBUG_FLAGS)
debug: prepare build

extra_debug: CC_FLAGS = $(EXTRA_DEBUG_FLAGS)
extra_debug: prepare build


build: $(objects)
	$(LD) $(CC_FLAGS) $(objects) -o $(BINARY_NAME)

$(objects): $(OBJ_DIR)/%.o: %.cpp
	$(CC) $(CC_FLAGS) $< -c -o $@


clean:
	@rm -rf $(OBJ_DIR) $(BINARY_NAME)
