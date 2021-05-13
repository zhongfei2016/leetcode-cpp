//
// leetcode-cpp
//

#include "FlattenSolution.h"

void FlattenSolution::flatten(TreeNode *root) {
    while (root != nullptr) {
        // 逐层遍历右子树，先将右子树接到同级左子树的最底层右节点，然后再将此同级左子树接到右子树的位置
        // 参考 https://leetcode.wang/leetcode-114-Flatten-Binary-Tree-to-Linked-List.html
        if(root->left == nullptr) {
            root = root->right;
        } else {
            // 记下此轮root的left
            TreeNode *left = root->left;
            // 找此轮root的left节点的最后一个右节点，将当前root的右节点其后面
            while (left->right!= nullptr){
                left = left->right;
            }
            left->right = root->right;
            // 将拼接好的左子树接到根节点的原右子树，然后原左子树置空
            root->right = root->left;
            root->left = nullptr;
            // 再遍历下一个右子树
            root = root->right;
        }
    }
}