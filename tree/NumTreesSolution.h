//
// leetcode-cpp
//
// 不同的二叉搜索树 https://leetcode-cn.com/problems/unique-binary-search-trees/

#ifndef LEETCODE_CPP_NUMTREESSOLUTION_H
#define LEETCODE_CPP_NUMTREESSOLUTION_H

#include <vector>

using namespace std;

class NumTreesSolution {
public:
    int numTrees(int n);
    int numTrees2(int n);
    int dfs(int n, vector<int>& memos);
};


#endif //LEETCODE_CPP_NUMTREESSOLUTION_H
