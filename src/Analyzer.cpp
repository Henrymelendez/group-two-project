#include "Analyzer.h"
#include <cstring>

Analyzer::Analyzer(int *data, unsigned int size) : size(size) {
    this->data = cloneValues(data, size);
}
Analyzer::~Analyzer() {
    delete[] data;
}
int* Analyzer::cloneValues(int* data, int size) {
    int* clone = new int[size];
    for (int i = 0; i < size; i++) {
        clone[i] = data[i];
    }
    return clone;
}
