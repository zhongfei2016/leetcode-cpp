//
// leetcode-cpp
//

/**
 * 二叉查找树（Binary Search Tree），（又：二叉搜索树，二叉排序树）
 * 它或者是一棵空树，或者是具有下列性质的二叉树：
 * 若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值；
 * 若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值；
 * 它的左、右子树也分别为二叉排序树。二叉搜索树作为一种经典的数据结构，
 * 它既有链表的快速插入与删除操作的特点，又有数组快速查找的优势；所以应用十分广泛，
 * 例如在文件系统和数据库系统一般会采用这种数据结构进行高效率的排序与检索操作。
 */
#include <climits>
#include "ValidBSTSolution.h"

bool validBST(TreeNode *root, long long low, long long high) {
    long long tempLow = low;
    long long tempHigh = high;
    if (root != nullptr) {
        bool left = true;
        bool right = true;
        if (root->left != nullptr) {
            //左子树非null，必须左子树值小于其根节点的值
            if (root->left->val >= root->val) {
                return false;
            }
            // 并且左子树值在上下界之间，相等也不行
            if (root->left->val <= low || root->left->val >= high) {
                return false;
            }
            // 而且由于是左子树，其后他的上界要受限制，也就是说它可以无限小，但不能无限大，再大不能大于其根节点的值
            if (root->val < high) {
                tempHigh = root->val;
            }
            left = validBST(root->left, low, tempHigh);
        }
        if (root->right != nullptr) {
            //右子树非null，必须右子树值大于其根节点的值
            if (root->right->val <= root->val) {
                return false;
            }
            // 并且右子树值在上下界之间，相等也不行
            if (root->right->val <= low || root->right->val >= high) {
                return false;
            }
            // 而且由于是右子树，其后他的下界要受限制，也就是说它可以无限大，但不能无限小，再小不能小于其根节点的值
            if (root->val > low) {
                tempLow = root->val;
            }
            right = validBST(root->right, tempLow, high);
        }
        // 每次取左右子树的并集
        return left & right;
    }
    // 根是null直接返回true
    return true;
}

bool ValidBSTSolution::isValidBST(TreeNode *root) {
    // TreeNode中是int值，要找一个一定小于其最小值和大于其最大值的数作为初始的上下界限
    long long low = LONG_LONG_MIN;
    long long high = LONG_LONG_MAX;
    if (root == nullptr) {
        return true;
    }
    return validBST(root, low, high);
}