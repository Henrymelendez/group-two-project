#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <string>

#include "Analyzer.h"
#include "StatisticsAnalyzer.h"
#include "SearchAnalyzer.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename.bin>\n";
        return 1;
    }

    std::string filename = argv[1];
    std::ifstream file(filename, std::ios::binary | std::ios::ate);
    if (!file) {
        std::cerr << "Error: Cannot open file " << filename << "\n";
        return 1;
    }

    std::streamsize fileSize = file.tellg();
    file.seekg(0, std::ios::beg);
    int numIntegers = fileSize / sizeof(int);

    std::vector<int> data(numIntegers);
    file.read(reinterpret_cast<char*>(data.data()), fileSize);
    file.close();

    std::cout << "Data file: " << filename << "\n";
    std::cout << "Number of integers: " << numIntegers << "\n\n";

    // Create copies of data for each analyzer
    std::vector<int> dataForStats = data;
    std::vector<int> dataForSearch = data;

    // Create and run analyzers
    std::vector<std::unique_ptr<Analyzer>> analyzers;
    analyzers.push_back(std::make_unique<StatisticsAnalyzer>(dataForStats.data(), dataForStats.size()));
    analyzers.push_back(std::make_unique<SearchAnalyzer>(dataForSearch.data(), dataForSearch.size()));

    for (const auto& analyzer : analyzers) {
        std::cout << analyzer->analyze() << "\n\n";
    }

    return 0;
}