#ifndef GROUP_TWO_PROJECT_SEARCHANALYZER_H
#define GROUP_TWO_PROJECT_SEARCHANALYZER_H
#include "Analyzer.h"
#include "sorting.h"
#include "search.h"
#include <string>

class SearchAnalyzer : public Analyzer {
public:
    SearchAnalyzer(int* data, int dataSize);
    std::string analyze() override;
};

#endif //GROUP_TWO_PROJECT_SEARCHANALYZER_H