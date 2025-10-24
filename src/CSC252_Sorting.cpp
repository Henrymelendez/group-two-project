#include "sorting.h"
#include <utility> // for std::swap

void selection_sort(int* values, int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;

        // Find index of smallest remaining element
        for (int j = i + 1; j < size; j++) {
            if (values[j] < values[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first unsorted position
        if (minIndex != i) {
            std::swap(values[i], values[minIndex]);
        }
    }
}
