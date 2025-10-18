#ifndef GROUP_TWO_PROJECT_STATISTICSANALYZER_H
#define GROUP_TWO_PROJECT_STATISTICSANALYZER_H

#include "Analyzer.h"
#include <string>

class StatisticsAnalyzer : public Analyzer {
public:
    StatisticsAnalyzer(int* data, int dataSize);
    std::string analyze() override;
};
#endif //GROUP_TWO_PROJECT_STATISTICSANALYZER_H