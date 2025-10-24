#include <iostream>
#include <string>
#include "StatisticsAnalyzer.h"

int main() {
    int arr[] = {2, 1, 3, 2};
    // Note: StatisticsAnalyzer clones and sorts internally
    StatisticsAnalyzer sa(arr, 4);
    std::string out = sa.analyze();

    std::string expected = "Statistics:\n  Min: 1\n  Max: 3\n  Mean: 2.00\n  Median: 2.00\n  Mode: 2";

    if (out != expected) {
        std::cerr << "test_statistics failed.\nExpected:\n" << expected << "\n\nGot:\n" << out << "\n";
        return 1;
    }
    return 0;
}

