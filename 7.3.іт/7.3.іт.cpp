#include <iostream>
#include <cmath>
#include <climits>

using namespace std;


// Виділення пам'яті для двовимірного масиву
int** allocateMatrix(int rows, int cols) {
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

// Звільнення пам'яті
void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void fillMatrix(int** matrix, int rows, int cols) {
    cout << "Enter elements of matrix (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(int** matrix, int rows, int cols) {
    cout << "\nMatrix:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

int calculateSumOfNonNegativeColumns(int** matrix, int rows, int cols) {
    int totalSum = 0;

    for (int j = 0; j < cols; ++j) {
        bool hasNegative = false;
        int columnSum = 0;

        for (int i = 0; i < rows; ++i) {
            if (matrix[i][j] < 0) {
                hasNegative = true;
            }
            columnSum += matrix[i][j];
        }

        if (!hasNegative) {
            totalSum += columnSum;
        }
    }
    return totalSum;
}

void findMinSumParallelToAntiDiagonal(int** matrix, int rows, int cols, int& resultMin) {

    int numDiagonals = rows + cols - 1;

    int* diagSums = new int[numDiagonals]; //динамічний масив для сум діагоналей

    for (int k = 0; k < numDiagonals; ++k) { // Ініціалізація нулями
        diagSums[k] = 0;
    }

    // Прохід по матриці і додавання модулів елементів до сум діагоналей
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int diagIndex = i + j; // Індекс діагоналі
            diagSums[diagIndex] += abs(matrix[i][j]);
        }
    }

    // Пошук мінімуму серед підрахованих сум
    int currentMin = INT_MAX;
    for (int k = 0; k < numDiagonals; ++k) {
        if (diagSums[k] < currentMin) {
            currentMin = diagSums[k];
        }
    }

    resultMin = currentMin;

    delete[] diagSums;
}

int main() {

    int k, n;

    cout << "Enter count of rows (k): ";
    cin >> k;
    cout << "Enter count of colls (n): ";
    cin >> n;

    if (k <= 0 || n <= 0) {
        cout << "Dimensionality must be additiona" << endl;
        return 1;
    }

	int** matrix = allocateMatrix(k, n); //виділення пам'яті

    fillMatrix(matrix, k, n);
    printMatrix(matrix, k, n);

    int sumResult = calculateSumOfNonNegativeColumns(matrix, k, n);
    cout << "1. Sum in col without negative numbers: " << sumResult << endl;

    int minDiagSum; // Змінна для отримання результату
    findMinSumParallelToAntiDiagonal(matrix, k, n, minDiagSum);
    cout << "2. Minimum among the sums of the diagonal modules: " << minDiagSum << endl;

	freeMatrix(matrix, k); //очищення пам'яті

    return 0;
}