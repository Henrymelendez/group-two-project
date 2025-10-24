#include <iostream>
#include "Analyzer.h"

class DummyAnalyzer : public Analyzer {
public:
    DummyAnalyzer(int* d, unsigned int s) : Analyzer(d, s) {}
    std::string analyze() override { return "ok"; }
};

int main() {
    int arr[] = {10, 20, 30};
    DummyAnalyzer da(arr, 3);
    int* clone = da.cloneValues(arr, 3);
    if (!clone) { std::cerr << "cloneValues returned null\n"; return 1; }
    for (int i = 0; i < 3; ++i) {
        if (clone[i] != arr[i]) {
            std::cerr << "cloneValues mismatch at " << i << ": expected " << arr[i] << " got " << clone[i] << "\n";
            delete[] clone;
            return 1;
        }
    }
    delete[] clone;
    return 0;
}

