# Variables
CC = gcc
CFLAGS = -Wall -g
TARGET = matrix_app
TEST_TARGET = matrix_test

# Default target
all: $(TARGET) $(TEST_TARGET)

# Link the main target binary
$(TARGET): main.o matrix.o
	$(CC) $(CFLAGS) -o $@ $^

# Compile main.c to main.o
main.o: main.c C_Programming.h
	$(CC) $(CFLAGS) -c $<

# Compile matrix.c to matrix.o
matrix.o: matrix.c C_Programming.h
	$(CC) $(CFLAGS) -c $<

#links the test binary
$(TEST_TARGET): test.o matrix.o
	$(CC) $(CFLAGS) -o $@ $^

#compiles test.c to test.o
test.o: test.c C_Programming.h
	$(CC) $(CFLAGS) -c $<

#function that removes all .o and executable files
clean:
	rm -f *.o $(TARGET) $(TEST_TARGET)

# Phony target for debugging make process
debug:
	@echo "Compiler: $(CC)"
	@echo "Compiler flags: $(CFLAGS)"
	@echo "Target: $(TARGET)"
	@echo "Test Target: $(TEST_TARGET)"
