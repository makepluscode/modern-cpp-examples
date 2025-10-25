# Compiler settings
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Target executable
TARGET = ex21.out

# Source file
SRC = ex21.cpp

# Build rule
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Clean rule
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: clean
