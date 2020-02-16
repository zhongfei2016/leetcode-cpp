//
// Created by ZHONGFEI on 2020/2/16.
//

#include "LevelOrderSolution.h"

void getCurLevelOrder(TreeNode* root, int level, vector<vector<int>> &res)
{
    if(root == nullptr) {
        return;
    }

    if(res.size() <= level) {
        vector<int> curRes;
        res.push_back(curRes);
    }
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