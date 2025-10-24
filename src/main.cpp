#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <string>

#include "Analyzer.h"
#include "StatisticsAnalyzer.h"
#include "SearchAnalyzer.h"
#include "DuplicatesAnalyzer.h"
#include "MissingAnalyzer.h"
#include "BinaryUtils.h"

int main(int argc, char* argv[]) {
    std::string filename;

    if (argc == 1) {
        filename = "data.bin";
        std::cout << "No filename provided, using default: " << filename << std::endl;

        // Check if file exists, if not create it
        std::ifstream checkFile(filename);
        if (!checkFile) {
            std::cout << "File not found. Creating " << filename << "...\n";
            createBinaryFile(filename);
        } else {
            checkFile.close();
        }
    } else if (argc == 2) {
        // One argument provided, use that.
        filename = argv[1];
    } else {
        // Too many arguments, show usage and exit.
        std::cerr << "Usage: " << argv[0] << " [filename.bin]\n";
        std::cerr << "If no filename is given, 'data.bin' will be created and used.\n";
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
    // We need separate copies of the data because each analyzer
    // will sort the data in-place.
    std::vector<int> dataForStats = data;
    std::vector<int> dataForSearch = data;
    std::vector<int> dataForDuplicates = data;
    std::vector<int> dataForMissing = data;

    std::vector<std::unique_ptr<Analyzer>> analyzers;
    analyzers.push_back(std::make_unique<StatisticsAnalyzer>(dataForStats.data(), dataForStats.size()));
    analyzers.push_back(std::make_unique<SearchAnalyzer>(dataForSearch.data(), dataForSearch.size()));
    analyzers.push_back(std::make_unique<DuplicatesAnalyzer>(dataForDuplicates.data(), dataForDuplicates.size()));
    analyzers.push_back(std::make_unique<MissingAnalyzer>(dataForMissing.data(), dataForMissing.size()));

    // --- Run and Print Analysis ---
    for (const auto& analyzer : analyzers) {
        std::cout << analyzer->analyze() << "\n\n";
    }

    return 0;
}