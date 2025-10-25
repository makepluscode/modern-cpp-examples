# Compiler settings
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pthread

# Target executable
TARGET = ex12.out

# Source file
SRC = ex12.cpp

# Build rule
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Clean rule
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: clean
