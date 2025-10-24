#ifndef GROUP_TWO_PROJECT_DUPLICATESANALYZER_H
#define GROUP_TWO_PROJECT_DUPLICATESANALYZER_H
#include "Analyzer.h"
#include <string>

/**
 * @brief Analyzer class that finds and reports duplicate values in the dataset
 *
 * This analyzer identifies which values appear more than once in the data
 * and reports statistics about duplicates.
 */
class DuplicatesAnalyzer : public Analyzer {
public:
    /**
     * @brief Constructor for DuplicatesAnalyzer
     * @param values Pointer to an array of integers
     * @param size Size of the array
     */
    DuplicatesAnalyzer(int* values, int size);

    /**
     * @brief Analyzes the data to find duplicate values
     * @return A string containing information about duplicates
     */
    std::string analyze() override;
};
#endif //GROUP_TWO_PROJECT_DUPLICATESANALYZER_H