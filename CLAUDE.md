# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Repository Overview

This is a learning repository containing self-contained examples demonstrating modern C++ features (C++11+), object-oriented programming concepts, and design patterns. Each example is in its own directory with a single `.cpp` file, a detailed bilingual README, and a Makefile.

## Building and Running Examples

Each example has its own Makefile for easy compilation:

```bash
# Navigate to any example directory
cd ex01-auto_type_deduction

# Build using the Makefile
make

# Run the executable
./ex01.out

# Clean up
make clean
```

**Manual compilation** (if needed):
```bash
# Standard examples (C++11)
g++ -std=c++11 -Wall -Wextra ex01.cpp -o ex01.out

# Threading examples (ex11, ex12) require -pthread
g++ -std=c++11 -Wall -Wextra -pthread ex11.cpp -o ex11.out

# ex52 requires C++14 for std::make_unique
g++ -std=c++14 -Wall -Wextra ex52.cpp -o ex52.out
```

## Code Organization

Examples are numbered by category:
- **ex01-ex05**: Modern C++ features (auto, smart pointers, ownership, weak_ptr)
- **ex11-ex12**: Concurrency (threads, mutexes)
- **ex21-ex22**: Functional programming (lambda functions and captures)
- **ex31**: nullptr usage
- **ex51-ex53**: Object-oriented programming (encapsulation, inheritance, abstraction)
- **ex81-ex83**: Design patterns (Singleton, Publisher-Subscriber, State)

Each example directory contains:
- **Makefile**: Standard build configuration with appropriate compiler flags
- **exNN.cpp**: Source code with bilingual (English/Korean) comments
- **README.md**: Bilingual documentation with detailed explanations

## Directory Structure

Standard structure for all examples:
```
exNN-example-name/
├── Makefile          # Build configuration
├── README.md         # Bilingual documentation (English/Korean)
└── exNN.cpp          # Source code with bilingual comments
```

## Documentation Style

**README.md files**: Each major section includes both English and Korean explanations. The pattern is:
- English paragraph
- Korean paragraph (한글 설명)

**Source code comments**: All code includes bilingual comments:
- English comment line
- Korean comment line (한글 주석)

**Technical terms**: When appropriate, technical terms are kept in English within Korean text (e.g., "mutex", "thread", "pointer", "lambda").

## Architecture Notes

**Self-contained examples**: Each example is completely independent with no shared code, libraries, or dependencies between examples. All code is in a single file per example.

**No global build system**: The repository intentionally has no root Makefile or CMakeLists.txt. Each example has its own Makefile and is meant to be built independently.

**Educational focus**: Examples are designed to demonstrate single concepts clearly rather than production-ready implementations.

**Compiler requirements**:
- Most examples: C++11 (`-std=c++11`)
- ex52-oop-inheritance: C++14 (`-std=c++14`) for `std::make_unique`
- Threading examples (ex11, ex12): Requires `-pthread` flag
