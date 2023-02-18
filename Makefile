CC = gcc
SRC_DIR = ./functions
BIN_DIR = ./bin
LIB_DIR = ./lib

# List all the source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

# Generate the corresponding object file names
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(BIN_DIR)/%.o,$(SRC_FILES))

# The default target, which will build the executable
all: $(BIN_DIR)/myprogram run

# Link the object files and libraries to create the executable
$(BIN_DIR)/myprogram: $(OBJ_FILES) $(LIB_DIR)/libparking.a
	$(CC) -o $@ $^ -lsqlite3

# Compile each source file into an object file
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c -o $@ $<

# Create the static library
$(LIB_DIR)/libparking.a: $(BIN_DIR)/place.o $(BIN_DIR)/factures.o
	ar rcs $@ $^

# Compile the place.c file into an object file
$(BIN_DIR)/place.o: $(SRC_DIR)/place.c
	$(CC) -c -o $@ $<

# Compile the facturesy.c file into an object file
$(BIN_DIR)/factures.o: $(SRC_DIR)/factures.c
	$(CC) -c -o $@ $<

# Clean the generated files
clean:
	rm -f $(BIN_DIR)/* $(LIB_DIR)/*

# Run the program
run:
	$(BIN_DIR)/myprogram