#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <string>

#include "Analyzer.h"
#include "StatisticsAnalyzer.h"
#include "SearchAnalyzer.h"

int main(int argc, char* argv[]) {
    std::string filename;

    if (argc == 1) {
        filename = "../data.bin";
        std::cout << "No filename provided, using default: " << filename << std::endl;
    } else if (argc == 2) {
        // One argument provided, use that.
        filename = argv[1];
    } else {
        // Too many arguments, show usage and exit.
        std::cerr << "Usage: " << argv[0] << " [filename.bin]\n";
        std::cerr << "If no filename is given, 'data.bin' will be used.\n";
        return 1;
    }

    // Open the binary file
    std::ifstream file(filename, std::ios::binary | std::ios::ate);
    if (!file) {
        std::cerr << "Error: Cannot open file " << filename << "\n";
        std::cerr << "Please ensure the file is in the same directory as the executable, or provide the full path.\n";
        return 1;
    }

    // Get file size
    std::streamsize fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    if (fileSize == 0) {
        std::cerr << "Error: File is empty: " << filename << "\n";
        file.close();
        return 1;
    }
    if (fileSize % sizeof(int) != 0) {
        std::cerr << "Error: File size is not a multiple of sizeof(int): " << filename << "\n";
        file.close();
        return 1;
    }

    int numIntegers = fileSize / sizeof(int);

    // Read all integers into a vector
    std::vector<int> data(numIntegers);
    if (!file.read(reinterpret_cast<char*>(data.data()), fileSize)) {
        std::cerr << "Error: Failed to read data from file: " << filename << "\n";
        file.close();
        return 1;
    }
    file.close();

    std::cout << "Data file: " << filename << "\n";
    std::cout << "Number of integers: " << numIntegers << "\n\n";

    // --- Create Analyzers ---
    // We need two separate copies of the data because both analyzers
    // will sort the data in-place.
    std::vector<int> dataForStats = data;
    std::vector<int> dataForSearch = data;

    std::vector<std::unique_ptr<Analyzer>> analyzers;
    analyzers.push_back(std::make_unique<StatisticsAnalyzer>(dataForStats.data(), dataForStats.size()));
    analyzers.push_back(std::make_unique<SearchAnalyzer>(dataForSearch.data(), dataForSearch.size()));

    // --- Run and Print Analysis ---
    for (const auto& analyzer : analyzers) {
        std::cout << analyzer->analyze() << "\n\n";
    }

    return 0;
}