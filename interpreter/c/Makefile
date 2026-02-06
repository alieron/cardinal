CC = gcc
CFLAGS = -Wall -Wextra -std=c11
CFLAGS_RELEASE = -O2
CFLAGS_DEBUG = -g -O0 -DDEBUG
BUILD_DIR = build
SRC_DIR = src
SOURCES = $(wildcard $(SRC_DIR)/*.c)
TARGET = $(BUILD_DIR)/cardinal

# Default file to run if none specified
FILE ?= ../../examples/hello_world

# Default target is debug
all: release

# Debug build (default)
debug: CFLAGS += $(CFLAGS_DEBUG)
debug: $(TARGET)

# Release build
release: CFLAGS += $(CFLAGS_RELEASE)
release: clean $(TARGET)

# Build the executable
$(TARGET): $(SOURCES)
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Run with a test file
run: debug
	./$(TARGET) $(FILE)

# Run with gdb
gdb: debug
	gdb --args $(TARGET) $(FILE)

# Run with valgrind (memory leak detection)
valgrind: debug
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET) $(FILE)

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all debug release gdb valgrind clean
