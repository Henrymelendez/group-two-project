#include <iostream>
#include <vector>
#include "DuplicatesAnalyzer.h"
#include "MissingAnalyzer.h"

/**
 * Test program for DuplicatesAnalyzer and MissingAnalyzer
 */
int main() {
    std::cout << "=== Analyzer Classes Test ===\n\n";

    // Test 1: DuplicatesAnalyzer with known duplicates
    std::cout << "Test 1: DuplicatesAnalyzer with duplicates\n";
    std::cout << "-------------------------------------------\n";
    std::vector<int> testData1 = {
        5, 10, 5, 20, 30, 10, 40, 5, 50, 20,
        60, 70, 10, 80, 90, 5, 100, 10
    };

    DuplicatesAnalyzer dupAnalyzer1(testData1.data(), testData1.size());
    std::cout << dupAnalyzer1.analyze() << "\n\n";

    // Test 2: DuplicatesAnalyzer with no duplicates
    std::cout << "Test 2: DuplicatesAnalyzer without duplicates\n";
    std::cout << "----------------------------------------------\n";
    std::vector<int> testData2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    DuplicatesAnalyzer dupAnalyzer2(testData2.data(), testData2.size());
    std::cout << dupAnalyzer2.analyze() << "\n\n";

    // Test 3: MissingAnalyzer with missing values
    std::cout << "Test 3: MissingAnalyzer with missing values\n";
    std::cout << "--------------------------------------------\n";
    std::vector<int> testData3 = {
        0, 1, 3, 5, 6, 8, 10, 12, 15, 18, 20
        // Missing: 2, 4, 7, 9, 11, 13, 14, 16, 17, 19
    };

    MissingAnalyzer missAnalyzer1(testData3.data(), testData3.size());
    std::cout << missAnalyzer1.analyze() << "\n\n";

    // Test 4: MissingAnalyzer with no missing values
    std::cout << "Test 4: MissingAnalyzer without missing values\n";
    std::cout << "-----------------------------------------------\n";
    std::vector<int> testData4 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    MissingAnalyzer missAnalyzer2(testData4.data(), testData4.size());
    std::cout << missAnalyzer2.analyze() << "\n\n";

    // Test 5: Combined test with larger dataset
    std::cout << "Test 5: Large dataset with gaps and duplicates\n";
    std::cout << "-----------------------------------------------\n";
    std::vector<int> testData5;
    // Create data with patterns: 0-100 but skip every 5th number, with duplicates
    for (int i = 0; i <= 100; i++) {
        if (i % 5 != 0) {
            testData5.push_back(i);
            if (i % 10 == 1) {
                testData5.push_back(i); // Add duplicate
            }
        }
    }

    std::cout << "Dataset size: " << testData5.size() << " values\n\n";

    DuplicatesAnalyzer dupAnalyzer3(testData5.data(), testData5.size());
    std::cout << dupAnalyzer3.analyze() << "\n\n";

    // Need a fresh copy since dupAnalyzer3 modified the data
    std::vector<int> testData5Copy = testData5;
    MissingAnalyzer missAnalyzer3(testData5Copy.data(), testData5Copy.size());
    std::cout << missAnalyzer3.analyze() << "\n\n";

    std::cout << "=== All Tests Complete ===\n";

    return 0;
}