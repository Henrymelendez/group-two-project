#include "MissingAnalyzer.h"
#include "sorting.h"
#include <sstream>
#include <set>
#include <vector>

MissingAnalyzer::MissingAnalyzer(int* values, int size)
    : Analyzer(values, size) {}

std::string MissingAnalyzer::analyze() {
    if (this->size == 0) {
        return "Missing Values Analysis:\n  No data to analyze.";
    }

    // Sort the data to find min and max easily
    selection_sort(this->data, this->size);

    int minVal = this->data[0];
    int maxVal = this->data[this->size - 1];

    // Put all values into a set for O(log n) lookup
    std::set<int> presentValues(this->data, this->data + this->size);

    // Find missing values in the range [minVal, maxVal]
    std::vector<int> missingValues;

    for (int i = minVal; i <= maxVal; i++) {
        if (presentValues.find(i) == presentValues.end()) {
            missingValues.push_back(i);
        }
    }

    // Build result string
    std::stringstream ss;
    ss << "Missing Values Analysis:\n";
    ss << "  Range: [" << minVal << ", " << maxVal << "]\n";
    ss << "  Total missing values: " << missingValues.size() << "\n";

    if (missingValues.empty()) {
        ss << "  All values in range are present.";
    } else {
        // Show first 20 missing values
        ss << "  Sample missing values: ";
        int displayCount = (missingValues.size() < 20) ? missingValues.size() : 20;

        for (int i = 0; i < displayCount; i++) {
            ss << missingValues[i];
            if (i < displayCount - 1) {
                ss << ", ";
            }
        }

        if (missingValues.size() > 20) {
            ss << ", ... (and " << (missingValues.size() - 20) << " more)";
        }
    }

    return ss.str();
}