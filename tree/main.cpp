//
// leetcode-cpp
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
#include "N_NodePreOrderSln.h"
#include "DirTreeSln.h"
#include "N_NodeLevelOrderSln.h"
#include "N_NodeMaxDepthSln.h"
#include "N_NodeSerializeSln.h"
#include "HasPathSumSln.h"
#include "SortArrayToBSTSln.h"

int main() {
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
    MaxDepthSolution maxDepthSln;
    maxDepthSln.maxDepth(levelOrderNode);

    // 从前序与中序遍历序列构造二叉树 https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
    BuildTreeSolution buildTreeSln;
    vector<int> preOrder = {3, 9, 20, 15, 7};
    vector<int> inOrder = {9, 3, 15, 20, 7};
    TreeNode *root = buildTreeSln.buildTree(preOrder, inOrder);

    // 二叉树展开为链表 https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/
    FlattenSolution flattenSln;
    TreeNode treeNode(3);
    TreeNode treeNodeL(9);
    TreeNode treeNodeR(20);
    TreeNode treeNodeRL(15);
    TreeNode treeNodeRR(7);
    treeNode.left = &treeNodeL;
    treeNode.right = &treeNodeR;
    treeNodeR.left = &treeNodeRL;
    treeNodeR.right = &treeNodeRR;
    flattenSln.flatten(&treeNode);

    Node n_nodeRoot(1);
    Node n_nodeChild1(3);
    Node n_nodeChild2(2);
    Node n_nodeChild3(4);
    Node n_nodeChild11(5);
    Node n_nodeChild12(6);
    n_nodeChild1.children.push_back(&n_nodeChild11);
    n_nodeChild1.children.push_back(&n_nodeChild12);
    n_nodeRoot.children.push_back(&n_nodeChild1);
    n_nodeRoot.children.push_back(&n_nodeChild2);
    n_nodeRoot.children.push_back(&n_nodeChild3);

    N_NodePreOrderSln n_nodePreOrderSln;
    auto preResults1 = n_nodePreOrderSln.preorder(&n_nodeRoot);
    auto preResults2 = n_nodePreOrderSln.preorder2(&n_nodeRoot);

    N_NodeLevelOrderSln nNodeLevelOrderSln;
    nNodeLevelOrderSln.levelOrder(&n_nodeRoot);

    DirTreeSln dirTreeSln;
    vector<string> dirTrees = {
            "|-B",
            "A",
            "|-B",
            "|-|-B",
            "|-C",
            "|-lib",
            "|-|-|-C",
            "|-|-D",
            "|-|-|-E"
    };
    StrNode *strNodeRoot = dirTreeSln.BuildNodeTree(dirTrees);
    std::unordered_set<string> delDirs = {"B", "C", "E"};
    vector<string> delResult;
    dirTreeSln.dfsDeleteDirs(strNodeRoot, delDirs, delResult);

    N_NodeMaxDepthSln nNodeMaxDepthSln;
    nNodeMaxDepthSln.maxDepth(&n_nodeRoot);
    nNodeMaxDepthSln.maxDepth2(&n_nodeRoot);

    N_NodeSerializeSln nNodeSerializeSln;
    auto serialData = nNodeSerializeSln.serialize(&n_nodeRoot);
    nNodeSerializeSln.deserialize(serialData);

    TreeNode hasPathTreeNode(3);
    TreeNode hasPathTreeNodeL(9);
    TreeNode hasPathTreeNodeR(20);
    TreeNode hasPathTreeNodeRL(15);
    TreeNode hasPathTreeNodeRR(7);
    hasPathTreeNode.left = &hasPathTreeNodeL;
    hasPathTreeNode.right = &hasPathTreeNodeR;
    hasPathTreeNodeR.left = &hasPathTreeNodeRL;
    hasPathTreeNodeR.right = &hasPathTreeNodeRR;
    HasPathSumSln hasPathSumSln;
    hasPathSumSln.hasPathSum(&hasPathTreeNode, 30);

    vector<int> sortedNumsForBST = {-10, -3, 0, 5, 9};
    SortArrayToBSTSln sortArrayToBstSln;
    sortArrayToBstSln.sortedArrayToBST(sortedNumsForBST);
    return 0;
}