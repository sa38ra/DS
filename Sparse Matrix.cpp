#include <iostream>
#include <vector> // Include vector for dynamic size
using namespace std;

int main() {
    // Original sparse matrix
    int sparseMatrix[4][5] = {
        { 0, 0, 3, 0, 4 },
        { 0, 0, 5, 7, 0 },
        { 0, 0, 0, 0, 0 },
        { 0, 2, 6, 0, 0 }
    };

    // Step 1: Count non-zero elements
    int size = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (sparseMatrix[i][j] != 0) {
                size++;
            }
        }
    }

    // Step 2: Create compact matrix using vectors
    vector<vector<int>> compactMatrix(3, vector<int>(size)); // 3 rows, size columns

    // Step 3: Fill compact matrix
    int k = 0; // Index for compactMatrix
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (sparseMatrix[i][j] != 0) {
                compactMatrix[0][k] = i;            // Row index
                compactMatrix[1][k] = j;            // Column index
                compactMatrix[2][k] = sparseMatrix[i][j]; // Value
                k++;
            }
        }
    }

    // Step 4: Print compact matrix
    cout << "Compact Matrix Representation:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < size; j++) {
            cout << compactMatrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
