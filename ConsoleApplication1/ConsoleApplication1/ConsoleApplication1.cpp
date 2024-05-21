#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

const int ROWS = 10000;
const int COLS = 10000;

// Function to generate a 2D array using array of pointers
int** generateMatrixPtr() {
    int** matrix = new int* [ROWS];
    for (int i = 0; i < ROWS; i++) {
        matrix[i] = new int[COLS];
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % 100; // random values between 0 and 99
        }
    }
    return matrix;
}

// Function to generate a 2D array using one-dimensional analog
int* generateMatrix1D() {
    int* matrix = new int[ROWS * COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i * COLS + j] = rand() % 100; // random values between 0 and 99
        }
    }
    return matrix;
}

// Function to find max element in a 2D array using array of pointers
int findMaxPtr(int** matrix) {
    int max = matrix[0][0];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }
    return max;
}

// Function to find max element in a 2D array using one-dimensional analog
int findMax1D(int* matrix) {
    int max = matrix[0];
    for (int i = 0; i < ROWS * COLS; i++) {
        if (matrix[i] > max) {
            max = matrix[i];
        }
    }
    return max;
}

// Function to find min element in a 2D array using array of pointers
int findMinPtr(int** matrix) {
    int min = matrix[0][0];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
        }
    }
    return min;
}

// Function to find min element in a 2D array using one-dimensional analog
int findMin1D(int* matrix) {
    int min = matrix[0];
    for (int i = 0; i < ROWS * COLS; i++) {
        if (matrix[i] < min) {
            min = matrix[i];
        }
    }
    return min;
}

// Function to calculate sum of elements in a 2D array using array of pointers
int calculateSumPtr(int** matrix) {
    int sum = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

// Function to calculate sum of elements in a 2D array using one-dimensional analog
int calculateSum1D(int* matrix) {
    int sum = 0;
    for (int i = 0; i < ROWS * COLS; i++) {
        sum += matrix[i];
    }
    return sum;
}

int main() {
    srand(time(0)); // seed for random number generation

    // Generate 2D array using array of pointers
    int** matrixPtr = generateMatrixPtr();

    // Measure execution time for array of pointers
    auto startPtr = std::chrono::high_resolution_clock::now();
    int maxPtr = findMaxPtr(matrixPtr);
    int minPtr = findMinPtr(matrixPtr);
    int sumPtr = calculateSumPtr(matrixPtr);
    auto endPtr = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationPtr = endPtr - startPtr;

    // Generate 2D array using one-dimensional analog
    int* matrix1D = generateMatrix1D();

    // Measure execution time for one-dimensional analog
    auto start1D = std::chrono::high_resolution_clock::now();
    int max1D = findMax1D(matrix1D);
    int min1D = findMin1D(matrix1D);
    int sum1D = calculateSum1D(matrix1D);
    auto end1D = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration1D = end1D - start1D;

    // Print results
    std::cout << "----Array of Pointers----" << std::endl;
    std::cout << "Maximum Element: " << maxPtr << std::endl;
    std::cout << "Minimum Element: " << minPtr << std::endl;
    std::cout << "Sum of Elements: " << sumPtr << std::endl;
    std::cout << "Execution Time: " << durationPtr.count() << " seconds" << std::endl;

    std::cout << "----One-Dimensional----" << std::endl;
    std::cout << "Maximum Element: " << max1D << std::endl;
    std::cout << "Minimum Element: " << min1D << std::endl;
    std::cout << "Sum of Elements: " << sum1D << std::endl;
    std::cout << "Execution Time: " << duration1D.count() << " seconds" << std::endl;

    // Deallocate memory
    for (int i = 0; i < ROWS; i++) {
        delete[] matrixPtr[i];
    }
    delete[] matrixPtr;
    delete[] matrix1D;

    return 0;
}