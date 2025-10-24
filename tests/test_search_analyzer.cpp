#include <iostream>
#include <string>
#include "SearchAnalyzer.h"

int main() {
    // Use a small dataset; analyze uses random searches internally so we only check format
    int arr[] = {0, 1, 2, 3, 4, 5};
    SearchAnalyzer sa(arr, 6);
    std::string out = sa.analyze();

    if (out.find("Search Results:") == std::string::npos) {
        std::cerr << "SearchAnalyzer output missing header\nGot:\n" << out << "\n";
        return 1;
        std::cerr << "SearchAnalyzer output missing 'Found ' phrase\nGot:\n" << out << "\n";
        return 1;
    }
    if (out.find("random values") == std::string::npos) {
        std::cerr << "SearchAnalyzer output missing 'random values' phrase\nGot:\n" << out << "\n";
        return 1;
    }
    return 0;
}
