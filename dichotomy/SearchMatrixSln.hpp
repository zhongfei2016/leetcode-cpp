//
// Created by ZHONGFEI on 2020/5/4.
// 从二维递增矩阵中搜索目标值，判断是否能搜到

#ifndef LEETCODE_CPP_SEARCHMATRIXSLN_HPP
#define LEETCODE_CPP_SEARCHMATRIXSLN_HPP

class SearchMatrixSln {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target);

    int binarySearch(vector<int> &array, int target);
};

bool SearchMatrixSln::searchMatrix(vector<vector<int> > &matrix, int target) {
    if (matrix.size() == 0 || matrix[0].size() == 0) {
        return false;
    }
    for (int i = 0; i < matrix.size(); i++) {
        if (matrix[i][0] > target) {
            continue;
        }
        if (matrix[i][matrix[i].size() - 1] < target) {
            continue;
        }
        int idx = binarySearch(matrix[i], target);
        if (idx == -1) {
            continue;
        }
        return true;
    }
    return false;
}

int SearchMatrixSln::binarySearch(vector<int> &array, int target) {
    int left = 0, right = array.size() - 1;
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (array[mid] == target) {
            return mid;
        }
        if (array[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

#endif //LEETCODE_CPP_SEARCHMATRIXSLN_HPP
