# setting compiler to be used for C as gcc
CC = gcc
# additional options for safeguards for the compiler
CFLAGS = -Wall -Wextra -std=c99

# list of source files
SRC = main.c matrix.c test.c
TEST_SRC = test.c

# list of object files needed to create executable
OBJ = main.o matrix.o
# list of object files needed to create test executable
TEST_OBJ = test.o matrix.o

# naming the executable
EXEC = matrix_app
# naming the test executable
TEST_EXEC = test_app

# building both executables
all: $(EXEC) $(TEST_EXEC)

# Main application executable
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)

# Test application executable
$(TEST_EXEC): $(TEST_OBJ)
	$(CC) $(CFLAGS) $(TEST_OBJ) -o $(TEST_EXEC) 

# Pattern to compile any .c to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJ) $(TEST_OBJ) $(EXEC) $(TEST_EXEC)

# Run the main program
run:
	./$(EXEC)

# Run the test program (optional target, add if needed)
test:
	./$(TEST_EXEC)