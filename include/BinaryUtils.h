#ifndef GROUP_TWO_PROJECT_BINARYUTILS_H
#define GROUP_TWO_PROJECT_BINARYUTILS_H
#include <string>

/**
 * @brief Creates a binary file with 1000 random integers (0-999)
 * @param filename The name of the binary file to create
 */
void createBinaryFile(std::string filename);

/**
 * @brief Writes an array of integers to a binary file
 * @param filename The name of the binary file to write to
 * @param values Pointer to the array of integers
 * @param length Number of integers to write
 */
void writeBinary(std::string filename, int* values, int length);

#endif //GROUP_TWO_PROJECT_BINARYUTILS_H