# setting compiler to be used for C as gcc
CC = gcc
# additional options for safeguards for the compiler
CFLAGS = -Wall -Wextra -std=c99

# list of source files
SRC = main.c matrix.c test.c

# List of object files
OBJ = $(SRC:.c=.o)

# Executable name
EXEC = matrix_app

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

run:
	./$(EXEC)