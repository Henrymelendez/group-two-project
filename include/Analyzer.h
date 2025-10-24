#ifndef GROUP_TWO_PROJECT_ANALYZER_H
#define GROUP_TWO_PROJECT_ANALYZER_H
#include <string>

class Analyzer {
protected:
    int* data;
    unsigned int size;
public:
    /**
     * @brief Constructor for Analyzer class
     * @param data Pointer to an array of integers
     * @param size Size of the array
     * */
    Analyzer(int* data, unsigned int size);

    /**
     * @brief Virtual destructor for Analyzer class
     */
    virtual ~Analyzer();
    /**
     * @brief Pure virtual function to analyze the data
     * @return A string representing the analysis result
     */
    virtual std::string analyze() = 0;

    int* cloneValues(int*, int);

};

#endif //GROUP_TWO_PROJECT_ANALYZER_H