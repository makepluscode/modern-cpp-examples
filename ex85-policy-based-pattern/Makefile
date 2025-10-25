# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Target executable
TARGET = ex85.out

# Source files
SRCS = ex85.cpp

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# Clean up
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: all clean
