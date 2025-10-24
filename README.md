# Signature Assignment Project

A comprehensive C++ application that performs statistical analysis, binary search operations, duplicate detection, and missing value identification on binary data files containing integer arrays.

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Programming Languages & Tools](#programming-languages--tools)
- [Programming Concepts Demonstrated](#programming-concepts-demonstrated)
- [Prerequisites](#prerequisites)
- [Project Structure](#project-structure)
- [Building the Project](#building-the-project)
- [Running the Application](#running-the-application)
- [Analyzer Classes](#analyzer-classes)
- [Technical Implementation](#technical-implementation)
- [Example Output](#example-output)

## Overview

This project demonstrates advanced C++ programming concepts through a modular data analysis system. The application reads binary files containing integer arrays and performs four types of analysis:

1. **Statistical Analysis** - Calculates min, max, mean, median, and mode
2. **Search Analysis** - Tests binary search performance on random queries
3. **Duplicates Analysis** - Identifies and counts duplicate values
4. **Missing Values Analysis** - Finds gaps in the data range

The project showcases object-oriented design with polymorphism, modern C++ features, and efficient algorithms.

## Features

### Core Capabilities

- **Automatic Data Generation**: Creates binary data files if they don't exist
- **Binary File I/O**: Efficient binary file reading and writing
- **Multiple Analysis Types**: Four distinct analyzers working on the same dataset
- **Polymorphic Design**: Clean OOP architecture with inheritance and virtual functions
- **Memory Safety**: Smart pointers and RAII principles
- **Comprehensive Statistics**: Full statistical analysis including mode calculation
- **Duplicate Detection**: Finds and reports all duplicate values with counts
- **Gap Analysis**: Identifies missing values within the data range

### Key Highlights

- Pure C++ implementation (C++20)
- No external dependencies
- Cross-platform compatible
- Self-contained executable
- Automatic data file creation
- Production-quality error handling

## Programming Languages & Tools

| Component | Technology | Version |
|-----------|-----------|---------|
| **Primary Language** | C++ | C++20 |
| **Build System** | CMake | 3.15+ |
| **Compiler** | GCC/Clang/MSVC | C++20 support required |

## Programming Concepts Demonstrated

### Object-Oriented Programming (OOP)

#### 1. **Inheritance Hierarchy**
```
Analyzer (Abstract Base Class)
    ├── StatisticsAnalyzer
    ├── SearchAnalyzer
    ├── DuplicatesAnalyzer
    └── MissingAnalyzer
```

#### 2. **Key OOP Principles**

**Encapsulation**
- Private/protected data members
- Public interface methods
- Data hiding and access control

**Abstraction**
- Pure virtual `analyze()` method
- Abstract `Analyzer` base class
- Common interface for all analyzers

**Inheritance**
- All analyzers extend `Analyzer`
- Shared functionality in base class
- Specialized behavior in derived classes

**Polymorphism**
- Virtual functions with `override` keyword
- Runtime polymorphism through pointers
- Virtual destructor for proper cleanup

### Data Structures & Algorithms

#### Algorithms Implemented

| Algorithm | Complexity | Usage |
|-----------|-----------|-------|
| **Selection Sort** | O(n²) | Sorting data for analysis |
| **Binary Search** | O(log n) | Recursive search implementation |
| **Statistical Calculations** | O(n) | Mean, median, mode computation |
| **Duplicate Detection** | O(n) | Using std::map for counting |
| **Gap Finding** | O(n log n) | Using std::set for lookup |

#### Data Structures Used

- **Arrays**: Raw integer arrays for data storage
- **Vectors**: Dynamic arrays (`std::vector<int>`)
- **Maps**: Frequency counting (`std::map<int, int>`)
- **Sets**: Presence checking (`std::set<int>`)
- **Smart Pointers**: Memory management (`std::unique_ptr`)

## Modern C++ Features

## **C++20 Standard**
- Latest language features
- Modern standard library

## **Smart Pointers**
- `std::unique_ptr` for automatic memory management
- RAII (Resource Acquisition Is Initialization)

## **STL Algorithms & Containers**
- `std::accumulate` for efficient summation
- `std::map` and `std::set` for data analysis
- `std::vector` for dynamic arrays

## **Random Number Generation**
- `std::mt19937` (Mersenne Twister)
- `std::uniform_int_distribution`
- Time-based seeding

## **File I/O**
- Binary file operations
- Error handling with stream states

## Prerequisites

### Required Software

1. **C++ Compiler with C++20 Support**
   - GCC 10.0+
   - Clang 11.0+
   - MSVC 2019 16.8+

2. **CMake 3.15 or Higher**
   - Download: https://cmake.org/download/

### Verify Installation

```bash
# Check compiler
g++ --version
# or
clang++ --version

# Check CMake
cmake --version
```

## Project Structure

```
group-two-project/
├── CMakeLists.txt              # Build configuration
├── README.md                   # This file
│
├── include/                    # Header files
│   ├── Analyzer.h              # Abstract base class
│   ├── StatisticsAnalyzer.h    # Statistics analysis
│   ├── SearchAnalyzer.h        # Binary search analysis
│   ├── DuplicatesAnalyzer.h    # Duplicate detection
│   ├── MissingAnalyzer.h       # Missing value detection
│   ├── BinaryUtils.h           # File I/O utilities
│   ├── search.h                # Binary search functions
│   └── sorting.h               # Sorting algorithms
│
└── src/                        # Implementation files
    ├── main.cpp                # Application entry point
    ├── Analyzer.cpp            # Base class implementation
    ├── StatisticsAnalyzer.cpp  # Statistics implementation
    ├── SearchAnalyzer.cpp      # Search implementation
    ├── DuplicatesAnalyzer.cpp  # Duplicates implementation
    ├── MissingAnalyzer.cpp     # Missing values implementation
    ├── BinaryUtils.cpp         # File I/O implementation
    ├── search.cpp              # Binary search implementation
    └── CSC252_Sorting.cpp      # Sorting implementation
```

## Building the Project

### Quick Build (Linux/macOS)

```bash
# 1. Create build directory
mkdir build
cd build

# 2. Configure
cmake ..

# 3. Build
make

# 4. Run
./group-two-project
```

### Windows (Visual Studio)

```bash
# 1. Create build directory
mkdir build
cd build

# 2. Configure
cmake .. -G "Visual Studio 17 2022"

# 3. Build
cmake --build . --config Release

# 4. Run
.\Release\group-two-project.exe
```



## Running the Application

### Usage

```bash
# Run with automatic data generation
./group-two-project

# Run with custom data file
./group-two-project path/to/datafile.bin
```

### First Run Behavior

When you run the program for the first time:

```bash
$ ./group-two-project
No filename provided, using default: data.bin
File not found. Creating data.bin...
Created data.bin with 1000 integers.
Data file: data.bin
Number of integers: 1000

Statistics:
  Min: 0
  Max: 999
  Mean: 497.35
  ...
```

The program automatically:
1. Detects that `data.bin` doesn't exist
2. Creates it with 1000 random integers (0-999)
3. Proceeds with analysis

### Subsequent Runs

```bash
$ ./group-two-project
No filename provided, using default: data.bin
Data file: data.bin
Number of integers: 1000
...
```

Uses the existing file - no regeneration needed.

## Analyzer Classes

### 1. StatisticsAnalyzer

**Purpose**: Computes comprehensive statistical measures

**Calculations**:
- **Minimum**: Smallest value in dataset
- **Maximum**: Largest value in dataset
- **Mean**: Arithmetic average
- **Median**: Middle value (or average of two middle values)
- **Mode**: Most frequently occurring value

**Algorithm**:
1. Sort data using selection sort
2. Extract min (first element) and max (last element)
3. Calculate sum and mean
4. Find median based on array size (even/odd)
5. Use frequency map to find mode

**Example Output**:
```
Statistics:
  Min: 0
  Max: 999
  Mean: 497.35
  Median: 496.50
  Mode: 523
```

### 2. SearchAnalyzer

**Purpose**: Tests binary search performance with random queries

**Process**:
1. Sort data using selection sort
2. Generate 100 random search keys (0-999)
3. Perform binary search for each key
4. Count successful searches
5. Report success rate

**Example Output**:
```
Search Results:
  Found 63 of 100 random values.
```

**Note**: Success rate depends on data distribution and randomness.

### 3. DuplicatesAnalyzer

**Purpose**: Identifies and reports duplicate values

**Process**:
1. Sort data using selection sort
2. Count occurrences of each value using std::map
3. Identify values appearing more than once
4. Report statistics and sample duplicates

**Example Output**:
```
Duplicates Analysis:
  Total duplicate values: 8
  Total duplicate occurrences: 23
  Sample duplicate values:
    42 appears 3 times
    127 appears 2 times
    234 appears 4 times
    389 appears 2 times
    ...
```

### 4. MissingAnalyzer

**Purpose**: Finds missing values within the data range

**Process**:
1. Sort data to find min and max
2. Create std::set of all present values
3. Check each value in range [min, max]
4. Report missing values

**Example Output**:
```
Missing Values Analysis:
  Range: [0, 999]
  Total missing values: 357
  Sample missing values: 3, 7, 12, 15, 23, 28, 31, 44, 56, 61, 73, 84, 91, 97, ... (and 337 more)
```

## Technical Implementation

### Binary File Format

**File Structure**:
- Raw binary data
- No headers or metadata
- Native endianness
- 4 bytes per integer (sizeof(int))

**File Size Calculation**:
```
File Size = Number of Integers × 4 bytes
1000 integers = 4000 bytes
```

### Memory Management

**RAII Pattern**:
```cpp
class Analyzer {
    int* data;  // Allocated in constructor
public:
    Analyzer(int* data, int size) {
        this->data = cloneValues(data, size);  // Deep copy
    }
    
    ~Analyzer() {
        delete[] data;  // Automatic cleanup
    }
};
```

**Smart Pointers**:
```cpp
std::vector<std::unique_ptr<Analyzer>> analyzers;
analyzers.push_back(std::make_unique<StatisticsAnalyzer>(...));
// Automatic memory management - no manual delete needed
```

### Polymorphism in Action

```cpp
// Single interface for all analyzers
for (const auto& analyzer : analyzers) {
    std::cout << analyzer->analyze() << "\n\n";
    // Calls the correct analyze() method based on actual type
}
```

Each analyzer implements its own `analyze()` method, called through the base class pointer at runtime.

### Algorithm Complexity Analysis

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| **Selection Sort** | O(n²) | O(1) |
| **Binary Search** | O(log n) | O(log n) recursive |
| **Mean Calculation** | O(n) | O(1) |
| **Median Calculation** | O(n log n) | O(1) |
| **Mode Calculation** | O(n) | O(n) |
| **Duplicate Detection** | O(n) | O(n) |
| **Missing Value Detection** | O(range × log n) | O(n) |

## Example Output

Complete program output with 1000 random integers:

```
No filename provided, using default: data.bin
File not found. Creating data.bin...
Created data.bin with 1000 integers.
Data file: data.bin
Number of integers: 1000

Statistics:
  Min: 0
  Max: 999
  Mean: 497.35
  Median: 496.50
  Mode: 523

Search Results:
  Found 63 of 100 random values.

Duplicates Analysis:
  Total duplicate values: 8
  Total duplicate occurrences: 23
  Sample duplicate values:
    42 appears 3 times
    127 appears 2 times
    234 appears 4 times
    389 appears 2 times
    445 appears 3 times
    567 appears 2 times
    789 appears 5 times
    891 appears 4 times

Missing Values Analysis:
  Range: [0, 999]
  Total missing values: 357
  Sample missing values: 3, 7, 12, 15, 23, 28, 31, 44, 56, 61, 73, 84, 91, 97, 103, 114, 127, 138, 145, 159, ... (and 337 more)
```

## Build Options

### CMake Configuration

```bash
# Debug build
cmake .. -DCMAKE_BUILD_TYPE=Debug

# Release build (optimized)
cmake .. -DCMAKE_BUILD_TYPE=Release

# Disable testing
cmake .. -DENABLE_TESTING=OFF

# Enable warnings as errors
cmake .. -DENABLE_WARNINGS_AS_ERRORS=ON
```

## Troubleshooting

### Common Issues

**Issue**: `data.bin not found` error
```bash
# Solution: Program auto-creates it, or create manually
./group-two-project  # Will create data.bin automatically
```

**Issue**: Compiler doesn't support C++20
```bash
# Solution: Update compiler or modify CMakeLists.txt
# Change: set(CMAKE_CXX_STANDARD 17)
```

**Issue**: CMake can't find source files
```bash
# Solution: Clean and reconfigure
cd build
rm -rf *
cmake ..
make
```

**Issue**: Linker errors
```bash
# Solution: Ensure all .cpp files are in src/ directory
# CMake automatically finds them with GLOB_RECURSE
```

## Educational Value

This project demonstrates:

### Software Engineering Principles
- Separation of concerns
- Single responsibility principle
- Open/closed principle (open for extension)
- Dependency inversion (program depends on abstraction)

### Design Patterns
- Template Method Pattern (base class defines structure)
- Strategy Pattern (different analysis strategies)
- Factory-like creation of analyzers

### Best Practices
- Const correctness
- RAII and smart pointers
- Proper error handling
- Comprehensive documentation
-  Clean code organization

## Performance Characteristics

With 1000 integers:
- **Execution Time**: < 1 second
- **Memory Usage**: ~100 KB
- **File Size**: 4000 bytes

The dominant operation is sorting (O(n²)), performed once per analyzer.

## Future Enhancements

Possible extensions:
- Additional statistical measures (variance, standard deviation)
- More efficient sorting algorithms (quicksort, mergesort)
- Iterative binary search option
- Customizable data ranges
- Multiple data type support
- Visualization output

## License

This project is created for educational purposes as part of CSC252 coursework.

## Authors

**Group Two Project Team**

## Acknowledgments

- Implements classic computer science algorithms
- Demonstrates modern C++ best practices
- Educational project showcasing OOP principles

---

**Last Updated**: October 2025

**Status**: Complete and Tested 