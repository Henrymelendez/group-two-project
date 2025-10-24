//
// Created by Henry Melendez on 10/24/25.
//

#ifndef GROUP_TWO_PROJECT_MISSINGANALYZER_H
#define GROUP_TWO_PROJECT_MISSINGANALYZER_H

#include "Analyzer.h"
#include <string>

/**
 * @brief Analyzer class that finds missing values in a range
 *
 * This analyzer identifies which values are missing from the dataset
 * within the range of minimum to maximum values present.
 */
class MissingAnalyzer : public Analyzer {
public:
    /**
     * @brief Constructor for MissingAnalyzer
     * @param values Pointer to an array of integers
     * @param size Size of the array
     */
    MissingAnalyzer(int* values, int size);

    /**
     * @brief Analyzes the data to find missing values in the range
     * @return A string containing information about missing values
     */
    std::string analyze() override;
};

#endif //GROUP_TWO_PROJECT_MISSINGANALYZER_H