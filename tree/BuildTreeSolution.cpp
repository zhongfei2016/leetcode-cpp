//
// leetcode-cpp
// [ 根节点, [左子树的前序遍历结果], [右子树的前序遍历结果] ]
// [ [左子树的中序遍历结果], 根节点, [右子树的中序遍历结果] ]

#include "BuildTreeSolution.h"

TreeNode *buildTreeTool(vector<int> &preorder, int pStart, int pEnd, vector<int> &inorder, int iStart, int iEnd) {
    if (pStart > pEnd || iStart > iEnd) {
        return nullptr;
    }
    // 对于本轮来说，前序遍历的第一个节点就是根节点
    TreeNode *root = new TreeNode(preorder[pStart]);
    int iRootIdx = 0;
    // 循环中旬遍历找到根节点在中序数组的索引，以根索引为中心，左边是左子树，右边是右子树
    for (int i = 0; i < inorder.size(); i++) {
        if (inorder[i] == preorder[pStart]) {
            iRootIdx = i;
            break;
        }
    }
    // 根节点索引减去中序数组的起始索引就是左数的元素个数
    int leftNum = iRootIdx - iStart;
    // 将左子树的内容传入下一轮循环
    root->left = buildTreeTool(preorder, pStart + 1, pStart + leftNum, inorder, iStart, iRootIdx - 1);
    root->right = buildTreeTool(preorder, pStart + leftNum + 1, pEnd, inorder, iRootIdx + 1, iEnd);
    return root;
}

// 前序遍历规则：根结点 ---> 左子树 ---> 右子树
// 中序遍历规则：左子树---> 根结点 ---> 右子树
// 后序遍历规则：左子树 ---> 右子树 ---> 根结点
// 规律：根据前序/后序 + 中序可以唯一确定一个二叉树结构
TreeNode *BuildTreeSolution::buildTree(vector<int> &preorder, vector<int> &inorder) {
    return buildTreeTool(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}