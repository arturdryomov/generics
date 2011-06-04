# Compiler and linker
CC = g++
LD = g++

# Flags of compiler
CFLAGS = -Wall 
LDFLAGS = $(CFLAGS)

# Output binary name
BINARY_NAME = app

# Directory of object files
OBJ_DIR = objects

# Names of object files
objects = $(OBJ_DIR)/car.o $(OBJ_DIR)/main.o

all:
	make target

target:
	@mkdir -p $(OBJ_DIR)
	make do-target

do-target: $(objects)
	$(LD) $(LDFLAGS) $(objects) -o $(BINARY_NAME)

clean:
	@rm -rf $(OBJ_DIR) $(BINARY_NAME)

$(objects): $(OBJ_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<
