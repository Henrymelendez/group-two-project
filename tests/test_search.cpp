#include <iostream>
#include "search.h"

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    // Present values
    if (!binary_search(arr, 5, 5)) { std::cerr << "binary_search: expected to find 5\n"; return 1; }
    if (!binary_search_recursive(arr, 1, 0, 4)) { std::cerr << "binary_search_recursive: expected to find 1\n"; return 1; }

    // Absent values
    if (binary_search(arr, 2, 5)) { std::cerr << "binary_search: unexpected find for 2\n"; return 1; }
    if (binary_search_recursive(arr, 8, 0, 4)) { std::cerr << "binary_search_recursive: unexpected find for 8\n"; return 1; }

    return 0;
}

