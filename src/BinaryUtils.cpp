#include "BinaryUtils.h"
#include <fstream>
#include <random>
#include <chrono>
#include <iostream>

void createBinaryFile(std::string filename) {
    // Generate 1000 random integers between 0 and 999
    const int DATA_SIZE = 1000;
    const int MIN_VALUE = 0;
    const int MAX_VALUE = 999;

    int* data = new int[DATA_SIZE];

    // Initialize random number generator
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 gen(seed);
    std::uniform_int_distribution<> distrib(MIN_VALUE, MAX_VALUE);

    // Generate random data
    for (int i = 0; i < DATA_SIZE; i++) {
        data[i] = distrib(gen);
    }

    // Write to binary file using the writeBinary function
    writeBinary(filename, data, DATA_SIZE);

    // Clean up
    delete[] data;

    std::cout << "Created " << filename << " with " << DATA_SIZE << " integers." << std::endl;
}

void writeBinary(std::string filename, int* values, int length) {
    // Open file in binary write mode
    std::ofstream file(filename, std::ios::binary);

    if (!file) {
        std::cerr << "Error: Cannot create file " << filename << std::endl;
        return;
    }

    // Write the array of integers to the file
    file.write(reinterpret_cast<const char*>(values), length * sizeof(int));

    if (!file) {
        std::cerr << "Error: Failed to write data to file " << filename << std::endl;
    }

    file.close();
}