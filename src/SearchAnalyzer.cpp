#include "SearchAnalyzer.h"
#include <sstream>
#include <random>
#include <chrono>

SearchAnalyzer::SearchAnalyzer(int* data, int dataSize)
    : Analyzer(data, dataSize) {
    selection_sort(this->data, this->size);
}

std::string SearchAnalyzer::analyze() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 gen(seed);
    std::uniform_int_distribution<> distrib(0, 999);

    int foundCount = 0;
    const int numSearches = 100;

    for (int i = 0; i < numSearches; ++i) {
        if (binary_search(this->data, distrib(gen), this->size)) {
            foundCount++;
        }
    }

    std::stringstream ss;
    ss << "Search Results:\n"
       << "  Found " << foundCount << " of " << numSearches << " random values.";

    return ss.str();
}