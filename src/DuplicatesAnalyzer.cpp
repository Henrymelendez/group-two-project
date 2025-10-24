#include "DuplicatesAnalyzer.h"
#include "sorting.h"
#include <sstream>
#include <map>
#include <vector>

DuplicatesAnalyzer::DuplicatesAnalyzer(int* values, int size)
    : Analyzer(values, size) {}

std::string DuplicatesAnalyzer::analyze() {
    if (this->size == 0) {
        return "Duplicates Analysis:\n  No data to analyze.";
    }

    // Sort the data to make finding duplicates easier
    selection_sort(this->data, this->size);

    // Count occurrences of each value
    std::map<int, int> counts;
    for (int i = 0; i < this->size; i++) {
        counts[this->data[i]]++;
    }

    // Find values that appear more than once
    std::vector<int> duplicateValues;
    int totalDuplicateCount = 0;

    for (const auto& pair : counts) {
        if (pair.second > 1) {
            duplicateValues.push_back(pair.first);
            totalDuplicateCount += pair.second;
        }
    }

    // Build result string
    std::stringstream ss;
    ss << "Duplicates Analysis:\n";

    if (duplicateValues.empty()) {
        ss << "  No duplicate values found.";
    } else {
        ss << "  Total duplicate values: " << duplicateValues.size() << "\n";
        ss << "  Total duplicate occurrences: " << totalDuplicateCount << "\n";

        // Show first 10 duplicate values and their counts
        ss << "  Sample duplicate values:\n";
        int displayCount = (duplicateValues.size() < 10) ? duplicateValues.size() : 10;

        for (int i = 0; i < displayCount; i++) {
            int value = duplicateValues[i];
            ss << "    " << value << " appears " << counts[value] << " times\n";
        }

        if (duplicateValues.size() > 10) {
            ss << "    ... and " << (duplicateValues.size() - 10) << " more";
        }
    }

    return ss.str();
}