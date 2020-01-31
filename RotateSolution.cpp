//
// Created by ZHONGFEI on 2020/1/29.
//

#include "RotateSolution.h"

void RotateSlnSwap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void RotateSolution::rotate(vector<vector<int>> &matrix) {
    // 先转置（对角线互换），再翻转每一行
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = i; j < matrix[i].size(); j++) {
            if (i != j) {
                RotateSlnSwap(&(matrix[i][j]), &(matrix[j][i]));
            }
        }
    }

    for (int i2 = 0; i2 < matrix.size(); i2++) {
        for (int j2 = 0; j2 < matrix[i2].size()/2; j2++) {
            RotateSlnSwap(&(matrix[i2][j2]), &(matrix[i2][matrix[i2].size()-j2-1]));
        }
    }
}

void rotate1(vector<vector<int>> &matrix)
{
    // 暂存[n][0]，然后[n][n]赋给[n][0]，[0][n]赋给[n][n]，[0][0]赋给[0][n]，完成一个元素一周的旋转
    // 然后再下一个，注意，每转一个，本行逆序对应位置的也已经转好了，所以循环n/2次即可
    // 比如 1,2,3,4，1转到4,4也转到对应位置，所以4不用再处理，同理3也不需要处理
    int n = matrix.size();
    for (int i = 0; i < (n + 1) / 2; i ++) {
        for (int j = 0; j < n / 2; j++) {
            int temp = matrix[n - 1 - j][i];
            matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1];
            matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 -i];
            matrix[j][n - 1 - i] = matrix[i][j];
            matrix[i][j] = temp;
        }
    }
}
