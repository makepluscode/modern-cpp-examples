# Compiler settings
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Target executable
TARGET = ex01.out

# Source file
SRC = ex01.cpp

# Build rule
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Clean rule
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: clean
