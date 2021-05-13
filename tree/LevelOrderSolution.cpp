//
// leetcode-cpp
//

#include "LevelOrderSolution.h"

void getCurLevelOrder(TreeNode* root, int level, vector<vector<int>> &res)
{
    if(root == nullptr) {
        return;
    }
    // 当前这一层没有数组，就塞一个
    if(res.size() <= level) {
        vector<int> curRes;
        res.push_back(curRes);
    }
    // 把当前的值塞到二维数组最后一个子数组里面
    res.at(level).push_back(root->val);

    getCurLevelOrder(root->left, level+1, res);
    getCurLevelOrder(root->right, level+1, res);
}

vector<vector<int>> LevelOrderSolution::levelOrder(TreeNode* root)
{
    vector<vector<int>> res;
    getCurLevelOrder(root, 0, res);
    return res;
}