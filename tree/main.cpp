//
// Created by ZHONGFEI on 2021/3/26.
//

#include "Common.h"
#include "InorderTraversalSolution.h"
#include "ValidBSTSolution.h"
#include "SymmetricSolution.h"
#include "LevelOrderSolution.h"
#include "MaxDepthSolution.h"
#include "BuildTreeSolution.h"
#include "FlattenSolution.h"
#include "NumTreesSolution.h"

int main()
{
    // 二叉树的中序遍历 https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
    // 前序遍历规则：根结点 ---> 左子树 ---> 右子树
    // 中序遍历规则：左子树---> 根结点 ---> 右子树
    // 后序遍历规则：左子树 ---> 右子树 ---> 根结点
    InorderTraversalSolution inorderTraversalSln;
    TreeNode nodeRL(3);
    TreeNode nodeR(2);
    nodeR.left = &nodeRL;
    TreeNode node(1);
    node.right = &nodeR;
    inorderTraversalSln.inorderTraversal(&node);

    // 不同的二叉搜索树 https://leetcode-cn.com/problems/unique-binary-search-trees/
    NumTreesSolution *numTreesSln = new NumTreesSolution();
    int numTreesRes = numTreesSln->numTrees(3);
    delete[] numTreesSln;

    // 验证二叉搜索树 https://leetcode-cn.com/problems/validate-binary-search-tree/
    ValidBSTSolution *validBstSln = new ValidBSTSolution();
    TreeNode *validBstNodeR = new TreeNode(2147483647);
    TreeNode *validBstNode = new TreeNode(-2147483648);
    validBstNode->right = validBstNodeR;
    bool validBstFlag = validBstSln->isValidBST(validBstNode);
    delete[] validBstSln;

    // 对称二叉树 https://leetcode-cn.com/problems/symmetric-tree/
    SymmetricSolution *symmetricSln = new SymmetricSolution();
    TreeNode *symmetricNode = new TreeNode(1);
    TreeNode *symmetricNodeL = new TreeNode(2);
    TreeNode *symmetricNodeR = new TreeNode(2);
    TreeNode *symmetricNodeLR = new TreeNode(3);
    TreeNode *symmetricNodeRR = new TreeNode(3);
    symmetricNodeL->right = symmetricNodeLR;
    symmetricNodeR->right = symmetricNodeRR;
    symmetricNode->left = symmetricNodeL;
    symmetricNode->right = symmetricNodeR;
    bool isSymmetric = symmetricSln->isSymmetric(symmetricNode);
    delete[] symmetricSln;

    // 二叉树层次遍历 https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
    LevelOrderSolution *levelOrderSln = new LevelOrderSolution();
    TreeNode *levelOrderNode = new TreeNode(3);
    TreeNode *levelOrderNodeL = new TreeNode(9);
    TreeNode *levelOrderNodeR = new TreeNode(20);
    TreeNode *levelOrderNodeRL = new TreeNode(15);
    TreeNode *levelOrderNodeRR = new TreeNode(7);
    levelOrderNode->left = levelOrderNodeL;
    levelOrderNode->right = levelOrderNodeR;
    levelOrderNodeR->left = levelOrderNodeRL;
    levelOrderNodeR->right = levelOrderNodeRR;
    levelOrderSln->levelOrder(levelOrderNode);
    delete[] levelOrderSln;

    //  二叉树的最大深度 https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
    MaxDepthSolution *maxDepthSln = new MaxDepthSolution();
    maxDepthSln->maxDepth(levelOrderNode);
    delete[] maxDepthSln;

    // 从前序与中序遍历序列构造二叉树 https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
    BuildTreeSolution buildTreeSln;
    vector<int> preOrder = {3, 9, 20, 15, 7};
    vector<int> inOrder = {9, 3, 15, 20, 7};
    TreeNode *root = buildTreeSln.buildTree(preOrder, inOrder);

    // 二叉树展开为链表 https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/
    FlattenSolution flattenSln;
    TreeNode *flattenNode = new TreeNode(3);
    TreeNode *flattenNodeL = new TreeNode(9);
    TreeNode *flattenNodeR = new TreeNode(20);
    TreeNode *flattenNodeRL = new TreeNode(15);
    TreeNode *flattenNodeRR = new TreeNode(7);
    flattenNode->left = flattenNodeL;
    flattenNode->right = flattenNodeR;
    flattenNodeR->left = flattenNodeRL;
    flattenNodeR->right = flattenNodeRR;
    flattenSln.flatten(flattenNode);
    return 0;
}