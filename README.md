# Signature Assignment Project

A C++ application that performs statistical analysis and search operations on binary data files containing integer arrays.

## Table of Contents
- [Overview](#overview)
- [Programming Languages](#programming-languages)
- [Programming Concepts](#programming-concepts)
- [Prerequisites](#prerequisites)
- [Project Structure](#project-structure)
- [Building the Project](#building-the-project)
- [Running the Application](#running-the-application)
- [Features](#features)
- [Technical Details](#technical-details)

## Overview

This project demonstrates data analysis capabilities by reading binary files containing integer arrays and performing:
- Statistical analysis (min, max, mean, median, mode)
- Binary search operations on sorted data

The application generates random test data and analyzes it using a modular, object-oriented architecture.

## Programming Languages

### Primary Languages
- **C++ (C++20)**: Core application logic and data structures
- **Python 3**: Data generation utility
- **CMake**: Build system configuration

## Programming Concepts

This project demonstrates several key programming concepts:

### Object-Oriented Programming (OOP)
- **Encapsulation**: Data and methods are bundled within classes (`Analyzer`, `StatisticsAnalyzer`, `SearchAnalyzer`)
- **Abstraction**: Abstract base class (`Analyzer`) defines common interface
- **Inheritance**: Derived classes (`StatisticsAnalyzer`, `SearchAnalyzer`) extend the base `Analyzer` class
- **Polymorphism**: Virtual functions allow runtime method resolution through base class pointers

### Specific OOP Features Used

#### Abstract Base Classes
```cpp
class Analyzer {
    virtual std::string analyze() = 0;  // Pure virtual function
};
```

#### Inheritance Hierarchy
```
Analyzer (Abstract Base Class)
    ├── StatisticsAnalyzer
    └── SearchAnalyzer
```

#### Polymorphism
- Virtual destructor for proper cleanup
- Virtual `analyze()` method overridden in derived classes
- Runtime polymorphism through `std::unique_ptr<Analyzer>`

### Data Structures & Algorithms

#### Algorithms
- **Selection Sort**: O(n²) sorting algorithm for data organization
- **Binary Search**: O(log n) recursive search algorithm
- **Statistical Calculations**: Mean, median, mode computation

#### Data Structures
- **Arrays**: Raw integer arrays for data storage
- **Vectors**: Dynamic arrays (`std::vector<int>`)
- **Maps**: Frequency counting with `std::map<int, int>`
- **Smart Pointers**: Memory management with `std::unique_ptr`

### Modern C++ Features

- **C++20 Standard**: Latest language features and improvements
- **Smart Pointers**: RAII and automatic memory management
- **STL Algorithms**: `std::accumulate` for efficient computations
- **Move Semantics**: Efficient resource transfer
- **Random Number Generation**: Modern `<random>` library with `std::mt19937`

### Software Design Patterns

- **Factory Pattern**: Creating multiple analyzer instances
- **Strategy Pattern**: Different analysis strategies (statistics vs. search)
- **Template Method Pattern**: Common initialization in base class

### Memory Management

- **Dynamic Memory Allocation**: `new` and `delete[]` for array cloning
- **RAII (Resource Acquisition Is Initialization)**: Automatic cleanup in destructors
- **Deep Copying**: Data cloning to prevent side effects

### File I/O Operations

- **Binary File Reading**: Direct memory mapping with `std::ifstream`
- **Binary File Writing**: Structured data output with Python's `struct` module
- **Error Handling**: Comprehensive file validation

## Prerequisites

### Required Software

1. **C++ Compiler** with C++20 support:
    - GCC 10+ or
    - Clang 11+ or
    - MSVC 2019+

2. **CMake** 3.15 or higher
    - Download from: https://cmake.org/download/

3. **Python 3.x**
    - For data generation script
    - Download from: https://www.python.org/downloads/

### Installation Verification

Check if you have the required tools:

```bash
# Check C++ compiler
g++ --version
# or
clang++ --version

# Check CMake
cmake --version

# Check Python
python --version
# or
python3 --version
```

## Project Structure

```
project-root/
├── CMakeLists.txt              # Build configuration
├── generate_data.py            # Python script to generate test data
├── data.bin                    # Generated binary data (auto-generated)
├── include/
│   ├── Analyzer.h              # Abstract base class
│   ├── StatisticsAnalyzer.h    # Statistics analysis interface
│   ├── SearchAnalyzer.h        # Search analysis interface
│   ├── sorting.h               # Sorting algorithms
│   └── search.h                # Search algorithms
├── src/
│   ├── main.cpp                # Application entry point
│   ├── Analyzer.cpp            # Base class implementation
│   ├── StatisticsAnalyzer.cpp  # Statistics implementation
│   ├── SearchAnalyzer.cpp      # Search implementation
│   ├── CSC252_Sorting.cpp      # Sorting implementation
│   └── search.cpp              # Binary search implementation
└── tests/                      # Unit tests (optional)
```

## Building the Project

### Step 1: Generate Build Files

Navigate to your project directory and create a build directory:

```bash
mkdir build
cd build
cmake ..
```

**On Windows (Visual Studio):**
```bash
mkdir build
cd build
cmake .. -G "Visual Studio 17 2022"
```

### Step 2: Build the Project

**On Linux/macOS:**
```bash
cmake --build .
```

**On Windows:**
```bash
cmake --build . --config Release
```

### Alternative: Using Make (Linux/macOS)

```bash
mkdir build
cd build
cmake ..
make
```

### Build Process Details

The build system will automatically:
1. Find the Python interpreter
2. Execute `generate_data.py` to create `data.bin`
3. Compile all C++ source files
4. Link the executable
5. Run tests (if `ENABLE_TESTING` is ON)

## Running the Application

### Basic Usage

**From the build directory:**

```bash
# Use default data.bin file
./group-two-project

# Specify a custom binary file
./group-two-project path/to/custom_data.bin
```

**On Windows:**
```bash
# Use default data.bin file
.\Release\group-two-project.exe

# Specify a custom binary file
.\Release\group-two-project.exe path\to\custom_data.bin
```

### Expected Output

```
Data file: ../data.bin
Number of integers: 1000

Statistics:
  Min: 0
  Max: 999
  Mean: 497.35
  Median: 496.50
  Mode: 523

Search Results:
  Found 63 of 100 random values.
```

## Features

### 1. Data Generation
- Generates 1000 random integers (0-999)
- Stores data in binary format for efficient I/O
- Automatic generation during build process

### 2. Statistical Analysis
- **Minimum**: Smallest value in dataset
- **Maximum**: Largest value in dataset
- **Mean**: Average of all values
- **Median**: Middle value when sorted
- **Mode**: Most frequently occurring value

### 3. Search Analysis
- Sorts data using selection sort
- Performs 100 binary searches with random keys
- Reports success rate of searches

### 4. Data Integrity
- Each analyzer works with independent data copies
- No side effects between analyses
- Proper memory management with RAII

## Technical Details

### Binary File Format

The `data.bin` file contains:
- **Format**: Raw binary, packed integers
- **Size**: 1000 integers × 4 bytes = 4000 bytes
- **Byte Order**: System native (little-endian on most systems)

### Algorithm Complexity

| Algorithm | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| Selection Sort | O(n²) | O(1) |
| Binary Search | O(log n) | O(log n) recursive |
| Mean Calculation | O(n) | O(1) |
| Median Calculation | O(n log n) | O(1) |
| Mode Calculation | O(n) | O(n) |

### Memory Management

- **Data Cloning**: Each analyzer creates its own copy of the data
- **Smart Pointers**: `std::unique_ptr` manages analyzer lifetimes
- **Manual Allocation**: Base class uses `new[]`/`delete[]` for arrays
- **RAII Principle**: Resources cleaned up in destructors

## Build Options

### CMake Configuration Options

```bash
# Disable testing
cmake .. -DENABLE_TESTING=OFF

# Enable warnings as errors
cmake .. -DENABLE_WARNINGS_AS_ERRORS=ON

# Custom build type
cmake .. -DCMAKE_BUILD_TYPE=Debug
# or
cmake .. -DCMAKE_BUILD_TYPE=Release
```

### Running Tests Only

If testing is enabled:

```bash
# Run all tests
ctest

# Run tests with verbose output
ctest --output-on-failure

# Run specific test
ctest -R test_name
```

## Troubleshooting

### Common Issues

**Problem**: `data.bin` not found
```bash
# Solution: Rebuild to regenerate data
cmake --build . --target GenerateData
```

**Problem**: Python not found during build
```bash
# Solution: Specify Python path explicitly
cmake .. -DPython_EXECUTABLE=/path/to/python3
```

**Problem**: Compiler doesn't support C++20
```bash
# Solution: Update compiler or change CMake C++ standard
# In CMakeLists.txt, change:
# set(CMAKE_CXX_STANDARD 17)
```

**Problem**: File permission errors
```bash
# Linux/macOS: Make executable
chmod +x group-two-project

# Windows: Run as administrator if needed
```

## Contributing

To extend this project:

1. **Add new analyzer types**: Inherit from `Analyzer` base class
2. **Implement new algorithms**: Add to `sorting.h` or `search.h`
3. **Add tests**: Create test files in `tests/` directory
4. **Modify data generation**: Edit `generate_data.py`

## License

This project is created for educational purposes as part of CSC252 coursework.

## Authors

Group Two Project Team

---

**Last Updated**: October 2025
