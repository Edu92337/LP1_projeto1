# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++23 -Wall -Wextra -Wpedantic -O2 -fstack-protector-strong
LDFLAGS := -fstack-protector-strong

# Directories
SRC_DIR := src
BUILD_DIR := build
BIN_DIR := .

# Files
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(SOURCES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
TARGET := $(BIN_DIR)/program

# Default target
all: $(TARGET)

# Link binary
$(TARGET): $(OBJECTS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Compile object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Create directories
$(BUILD_DIR) $(BIN_DIR):
	mkdir -p $@

# Clean
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Phony targets
.PHONY: all clean