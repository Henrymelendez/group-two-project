#include "search.h"
#inlcude <iostream>


bool binary_search_recursive(int* values, int key, int start, int end) 
{
	if (start > end) {
		return false; // Base case: key not found
	}
	int mid = start + (end - start) / 2; // Calculate mid index
	if (values[mid] == key) {
		return true; // Key found
	} else if (values[mid] > key) {
		return binary_search_recursive(values, key, start, mid - 1); // Search in the left half
	} else {
		return binary_search_recursive(values, key, mid + 1, end); // Search in the right half
	}
}

bool binary_search(int* values, int key, int size) 
{
	return binary_search_recursive(values, key, 0, size - 1);
}
