#include <iostream>
#include "sorting.h"

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int expected[] = {1, 2, 5, 5, 6, 9};
    selection_sort(arr, 6);
    for (int i = 0; i < 6; ++i) {
        if (arr[i] != expected[i]) {
            std::cerr << "test_sorting failed at index " << i << ": expected " << expected[i] << " got " << arr[i] << "\n";
            return 1;
        }
    }
    return 0;
}

