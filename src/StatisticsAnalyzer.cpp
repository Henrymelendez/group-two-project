#include "StatisticsAnalyzer.h"
#include <sstream>
#include <numeric>
#include <map>

StatisticsAnalyzer::StatisticsAnalyzer(int* data, int dataSize)
    : Analyzer(data, dataSize) {}

std::string StatisticsAnalyzer::analyze() {
    if (this->size == 0) return "Statistics:\n  No data to analyze.";

    selection_sort(this->data, this->size);

    int minVal = this->data[0];
    int maxVal = this->data[this->size - 1];

    double sum = std::accumulate(this->data, this->data + this->size, 0.0);
    double mean = sum / this->size;

    double median;
    if (this->size % 2 == 0) {
        median = (this->data[this->size / 2 - 1] + this->data[this->size / 2]) / 2.0;
    } else {
        median = this->data[this->size / 2];
    }

    std::map<int, int> counts;
    for (int i = 0; i < this->size; ++i) counts[this->data[i]]++;

    int mode = this->data[0];
    int maxCount = 0;
    for (const auto& pair : counts) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mode = pair.first;
        }
    }

    std::stringstream ss;
    ss.precision(2);
    ss << std::fixed << "Statistics:\n"
       << "  Min: " << minVal << "\n"
       << "  Max: " << maxVal << "\n"
       << "  Mean: " << mean << "\n"
       << "  Median: " << median << "\n"
       << "  Mode: " << mode;

    return ss.str();
}