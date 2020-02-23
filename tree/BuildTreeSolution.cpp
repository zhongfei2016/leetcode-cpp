//
// Created by ZHONGFEI on 2020/2/23.
//

#include "BuildTreeSolution.h"

TreeNode *buildTreeTool(vector<int> &preorder, int pStart, int pEnd, vector<int> &inorder, int iStart, int iEnd) {
    if (pStart > pEnd || iStart > iEnd) {
        return nullptr;
    }
    TreeNode *root = new TreeNode(preorder[pStart]);
    int iRootIdx = 0;
    for (int i = 0; i < inorder.size(); i++) {
        if (inorder[i] == preorder[pStart]) {
            iRootIdx = i;
            break;
        }
    }
    int leftNum = iRootIdx - iStart;
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