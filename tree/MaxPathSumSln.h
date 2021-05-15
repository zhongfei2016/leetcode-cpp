//
// leetcode-cpp
//

#ifndef LEETCODE_CPP_MAXPATHSUMSLN_H
#define LEETCODE_CPP_MAXPATHSUMSLN_H

#include <Common.h>

class MaxPathSumSln {
public:
    int maxPathSum(TreeNode *root);

    int dfs(TreeNode *curNode, int* maxVal);
};


#endif //LEETCODE_CPP_MAXPATHSUMSLN_H
