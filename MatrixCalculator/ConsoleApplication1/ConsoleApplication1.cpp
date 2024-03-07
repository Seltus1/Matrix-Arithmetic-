#include <iostream>
#include <vector>
using namespace std;
std::vector<vector<float>> invalidMatrix() {
    cout << "Invalid matrix operation\n";
    vector<vector<float>> error(1, vector<float>(1, 0));
    return error;
}

std::vector<vector<float>> scalarMultiple(const std::vector<std::vector<float>>& A, float scalar) {
    //Matrix A row count
    int m = A.size();
    //Matrix A column count
    int n1 = A[0].size();

    vector<vector<float>> result(m, vector<float>(n1));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n1; j++) {
            result[i][j] = A[i][j] * scalar;
        }
    }
    return result;
}

std::vector<vector<float>> addMatrix(const std::vector<std::vector<float>>& A, const std::vector<std::vector<float>>& B) {
    //Matrix A row count
    int m = A.size();
    //Matrix A column count
    int n1 = A[0].size();
    //Matrix B row count
    int n = B.size();
    //Matrix B column count
    int p = B[0].size();

    if (m != n || n1 != p) {
        return invalidMatrix();
    }
    vector<vector<float>> result(m, vector<float>(n1));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n1; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

std::vector<vector<float>> multiplyMatrix(const std::vector<std::vector<float>>& A, const std::vector<std::vector<float>>& B ) {
    //mxn, nxp

    //Matrix A row count
    int m = A.size(); 
    //Matrix A column count
    int n1 = A[0].size();
    //Matrix B row count
    int n = B.size();
    //Matrix B column count
    int p = B[0].size();

    // if column and rows dont match, abort
    if (n1 != n) {
        return invalidMatrix();
    }
    vector<vector<float>> result(m, vector<float>(p,0));
    //Iterate through the row elements of matrix A
    for (int i = 0; i < m; i++){
        //Iterate through the column elements of matrix B
        for (int j = 0; j < p; j++) {
            //Going through the correct elements and multiplying them
            for (int k = 0; k < n1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

void printMatrix(const std::vector<std::vector<float>>& matrix) {
    for (const auto& row : matrix) {
        for (float value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}
int main()
{
    vector<vector<float>> A = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    vector<vector<float>> B = {
        {10,11,12},
        {13,14,15},
        {16,17,18}
    };

    vector<vector<float>> C = {
        {10,11,12},
        {13,14,15},
    };

    vector<vector<float>> D = {
        {1,2},
        {3,4},
        {5,6}
    };

    //printMatrix(multiplyMatrix(A, C));
    //printMatrix(addMatrix(A, C));
    printMatrix(addMatrix(A, scalarMultiple(A, -8.7)));
    //printMatrix(multiplyMatrix(C, D));
    return 1;

}