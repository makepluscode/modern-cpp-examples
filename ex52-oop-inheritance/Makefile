# Compiler settings
CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra

# Target executable
TARGET = ex52.out

# Source file
SRC = ex52.cpp

# Build rule
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Clean rule
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: clean
