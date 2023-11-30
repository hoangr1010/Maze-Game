#---------------------------------------------
# Date: Nov.21 2023
# Name: Joseph Foote
# Description: Makefile
#---------------------------------------------
# Define compiler
CC = gcc

# Define flags
CFLAGS = -Wall -lm -lncurses -ltinfo

# Create Source files of all c extensions
SRC = $(wildcard *.c)

# Create list of Object files from c extensions
OBJ = $(SRC:.c=.o)

# Executable name
EXEC = mazerun

# Default target
all: $(EXEC)

# Compile source files into object files
%.o: %.c pointerFun.h
	$(CC) $(CLFAGS) -c $< -o $@

# Link objects and create the executable
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

# Clean up object files and the executable
clean:
	rm -f $(OBJ) $(EXEC)

test:
	make
	./$(EXEC)
	