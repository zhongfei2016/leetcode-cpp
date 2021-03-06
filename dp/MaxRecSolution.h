//
// leetcode-cpp
//
// 最大矩形 https://leetcode-cn.com/problems/maximal-rectangle/

#ifndef LEETCODE_CPP_MAXRECSOLUTION_H
#define LEETCODE_CPP_MAXRECSOLUTION_H

#include <vector>

using namespace std;

class MaxRecSolution {
public:
    int maximalRectangle(vector<vector<char>>& matrix);
    int maximalRectangle2(vector<vector<char>>& matrix);
    int largestRectangleArea(vector<int>& heights);
};


#endif //LEETCODE_CPP_MAXRECSOLUTION_H
