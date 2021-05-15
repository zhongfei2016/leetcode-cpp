//
// leetcode-cpp
//

#include "LevelOrderSolution.h"
#include <queue>

void getCurLevelOrder(TreeNode *root, int level, vector<vector<int>> &res) {
    if (root == nullptr) {
        return;
    }
    // 当前这一层没有数组，就塞一个
    if (res.size() <= level) {
        vector<int> curRes;
        res.push_back(curRes);
    }
    // 把当前的值塞到二维数组最后一个子数组里面
    res.at(level).push_back(root->val);

    getCurLevelOrder(root->left, level + 1, res);
    getCurLevelOrder(root->right, level + 1, res);
}

vector<vector<int>> LevelOrderSolution::levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    getCurLevelOrder(root, 0, res);
    return res;
}

vector<vector<int>> LevelOrderSolution::levelOrder2(TreeNode *root) {
    if (root == nullptr) {
        return {};
    }
    vector<vector<int>> res;
    queue<TreeNode *> que;
    que.push(root);
    while (!que.empty()) {
        int size = que.size();
        vector<int> temp;
        for (int i = 0; i < size; i++) {
            auto item = que.front();
            que.pop();
            temp.push_back(item->val);
            if (item->left != nullptr) {
                que.push(item->left);
            }
            if (item->right != nullptr) {
                que.push(item->right);
            }
        }
        res.push_back(temp);
    }
    return res;
}