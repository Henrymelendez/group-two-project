#include <iostream>
#include <fstream>
#include "BinaryUtils.h"

/**
 * Test program to demonstrate createBinaryFile and writeBinary functions
 */
int main() {
    std::cout << "=== Binary File Utilities Test ===\n\n";

    // Test 1: Create a binary file with random data
    std::cout << "Test 1: Creating binary file with random data...\n";
    createBinaryFile("test_data.bin");
    std::cout << "\n";

    // Test 2: Create custom data and write to file
    std::cout << "Test 2: Writing custom data to binary file...\n";
    int customData[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int customLength = 10;

    writeBinary("custom_data.bin", customData, customLength);
    std::cout << "Created custom_data.bin with " << customLength << " integers.\n\n";

    // Test 3: Verify the custom file by reading it back
    std::cout << "Test 3: Verifying custom data file...\n";
    std::ifstream verifyFile("custom_data.bin", std::ios::binary);

    if (verifyFile) {
        int readData[10];
        verifyFile.read(reinterpret_cast<char*>(readData), customLength * sizeof(int));

        std::cout << "Data read from file: ";
        for (int i = 0; i < customLength; i++) {
            std::cout << readData[i];
            if (i < customLength - 1) std::cout << ", ";
        }
        std::cout << "\n";

        // Check if data matches
        bool matches = true;
        for (int i = 0; i < customLength; i++) {
            if (readData[i] != customData[i]) {
                matches = false;
                break;
            }
        }

        if (matches) {
            std::cout << "✓ Data verification successful!\n";
        } else {
            std::cout << "✗ Data verification failed!\n";
        }

        verifyFile.close();
    } else {
        std::cout << "Error: Could not open file for verification.\n";
    }

    std::cout << "\n=== Test Complete ===\n";

    return 0;
}