// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "MatrixMultiplier.h"
using namespace std;
std::vector<vector<int>> MultiplyMatrix(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B ) {
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
        cout << "Invalid matrix operation\n";
        vector<vector<int>> error(1, vector<int>(1, 0));
        return error;
    }
    vector<vector<int>> result(m, vector<int>(p,0));
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

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}
int main()
{
    vector<vector<int>> A = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    vector<vector<int>> B = {
        {10,11,12},
        {13,14,15},
        {16,17,18}
    };

    vector<vector<int>> C = {
        {10,11,12},
        {13,14,15},
    };

    vector<vector<int>> D = {
        {1,2},
        {3,4},
        {5,6}
    };

    printMatrix(MultiplyMatrix(A, D));

    //printMatrix(MultiplyMatrix(C, D));
    return 1;

}


