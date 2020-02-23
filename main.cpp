#include <iostream>

#include "SolutionLengthOfLongestSubstring.h"
#include "SolutionCountSmaller.h"
#include "SolutionFindMedianSortedArrays.h"
#include "SolutionLongestPalindrome.h"
#include "SolutionPatternMatch.h"
#include "SolutionMaxArea.h"
#include "SolutionThreeSum.h"
#include "LetterCombiSolution.h"
#include "SolutionBracketValid.h"
#include "GenerateBacktraceSolution.h"
#include "MergeKListsSolution.h"
#include "NextPermutationSolution.h"
#include "LongValidBracketSolution.h"
#include "SearchSolution.h"
#include "SearchRangeSolution.h"
#include "CombinationSumSolution.h"
#include "TrapSolution.h"
#include "PremuteSolution.h"
#include "RotateSolution.h"
#include "GroupAnagramsSolution.h"
#include "MaxSubArraySolution.h"
#include "CanJumpSolution.h"
#include "MergeIntervalSolution.h"
#include "UniquePathSolution.h"
#include "MinPathSumSolution.h"
#include "ClimbStairSolution.h"
#include "MinDistanceSolution.h"
#include "SortColorSolution.h"
#include "MinWindowSolution.h"
#include "SubsetSolution.h"
#include "WordExistSolution.h"
#include "MaxRecSolution.h"
#include "tree/InorderTraversalSolution.h"
#include "tree/NumTreesSolution.h"
#include "tree/ValidBSTSolution.h"
#include "tree/SymmetricSolution.h"
#include "tree/LevelOrderSolution.h"
#include "tree/MaxDepthSolution.h"
#include "tree/BuildTreeSolution.h"
#include "tree/FlattenSolution.h"

int main() {
    // 最长不重复子串 https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
    string str = "abcabdcdd";
    SolutionLengthOfLongestSubstring *lols = new SolutionLengthOfLongestSubstring();
    int maxLen = lols->lengthOfLongestSubstring(str);
    delete[] lols;

    // 计算右侧小于当前元素的个数 https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/
    std::vector<int> nums = {5, 3, 6, 1};
    SolutionCountSmaller *cs = new SolutionCountSmaller();
    vector<int> calNums = cs->countSmaller(nums);
    for (int i = 0; i < calNums.size(); i++) {
        cout << calNums[i] << endl;
    }
    delete[] cs;

    // 两数组中位数 https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
    std::vector<int> nums1 = {5, 3, 6, 1};
    std::vector<int> nums2 = {2, 4};
    SolutionFindMedianSortedArrays *fmsa = new SolutionFindMedianSortedArrays();
    fmsa->findMedianSortedArrays(nums1, nums2);
    delete[] fmsa;

    // 最长回文子串 https://leetcode-cn.com/problems/longest-palindromic-substring/
    SolutionLongestPalindrome *lp = new SolutionLongestPalindrome();
    lp->longestPalindrome("aaaa");
    delete[] lp;

    // 正则匹配 https://leetcode-cn.com/problems/regular-expression-matching/
    SolutionPatternMatch *pm = new SolutionPatternMatch();
    bool match = pm->isMatch("a", ".*..a*");
    delete[] pm;

    // 盛水最多的容器 https://leetcode-cn.com/problems/container-with-most-water/
    SolutionMaxArea *ma = new SolutionMaxArea();
    vector<int> maVec = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int maxArea = ma->maxArea(maVec);
    delete[] ma;

    // 三数之和 https://leetcode-cn.com/problems/3sum/
    SolutionThreeSum *ts = new SolutionThreeSum();
    vector<int> numsTs = {0, 0, 0};
    ts->threeSum(numsTs);
    delete[] ts;

    // 电话号码数字组合 https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
    LetterCombiSolution *lcs = new LetterCombiSolution();
    lcs->letterCombinations("23");
    delete[] lcs;

    // 判断有效的括号，比如{}[]()  [[()]]
    SolutionBracketValid *sbv = new SolutionBracketValid();
    std::cout << sbv->isValid(")}{({))[{{[}") << std::endl;
    delete[] sbv;

    //给出 n 生成全部有效括号组合，回溯法 https://leetcode-cn.com/problems/generate-parentheses/
    GenerateBacktraceSolution *gbs = new GenerateBacktraceSolution();
    gbs->generateParenthesis(3);
    delete[] gbs;

    // 合并 k 个排序链表，返回合并后的排序链表  https://leetcode-cn.com/problems/merge-k-sorted-lists/
    MergeKListsSolution *mkls = new MergeKListsSolution();
    ListNode *ln1 = new ListNode(1);
    ln1->next = new ListNode(4);
    ln1->next->next = new ListNode(5);
    ListNode *ln2 = new ListNode(1);
    ln2->next = new ListNode(3);
    ln2->next->next = new ListNode(4);
    vector<ListNode *> lns;
    lns.push_back(ln1);
    lns.push_back(ln2);
    mkls->mergeKLists(lns);
    delete[] mkls;

    // 获取当前排列的下一排字典序的排列 https://leetcode-cn.com/problems/next-permutation/
    NextPermutationSolution *nps = new NextPermutationSolution();
    vector<int> npsVec = {1, 1};
    nps->nextPermutation(npsVec);
    delete[] nps;

    // 最长有效括号  https://leetcode-cn.com/problems/longest-valid-parentheses/
    LongValidBracketSolution *lvbs = new LongValidBracketSolution();
    lvbs->longestValidParentheses("(()");
    delete[] lvbs;

    //搜索旋转排序数组 https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
    SearchSolution *ss = new SearchSolution();
    vector<int> ssVec = {4, 5, 6, 7, 1, 2};
    ss->search(ssVec, 1);
    delete[] ss;

    // 在排序数组中查找元素的第一个和最后一个位置 https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
    SearchRangeSolution *srs = new SearchRangeSolution();
    vector<int> srsVec = {4, 5, 6, 7, 7, 2};
    srs->searchRange(srsVec, 7);
    delete[] srs;

    // 组合总和 回溯算法 https://leetcode-cn.com/problems/combination-sum/
    CombinationSumSolution *css = new CombinationSumSolution();
    vector<int> cssVec = {4, 5, 6, 7, 7, 2};
    css->combinationSum(cssVec, 9);
    delete[] css;

    // 接雨水 https://leetcode-cn.com/problems/trapping-rain-water/
    TrapSolution *trapSln = new TrapSolution();
    vector<int> trapSlnVec = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    trapSln->trap(trapSlnVec);
    delete[] trapSln;

    // 全排列 https://leetcode-cn.com/problems/permutations/
    PremuteSolution *premuteSln = new PremuteSolution();
    vector<int> premuteSlnVec = {1, 2, 3};
    premuteSln->permute(premuteSlnVec);
    delete[] premuteSln;

    // 旋转图像 https://leetcode-cn.com/problems/rotate-image/
    RotateSolution *rotateSln = new RotateSolution();
    vector<vector<int>> rotateVec;
    vector<int> rotateVec1 = {1, 2, 3};
    vector<int> rotateVec2 = {4, 5, 6};
    vector<int> rotateVec3 = {7, 8, 9};
    rotateVec.push_back(rotateVec1);
    rotateVec.push_back(rotateVec2);
    rotateVec.push_back(rotateVec3);
    rotateSln->rotate(rotateVec);
    delete[] rotateSln;

    // 字母异位词分组 https://leetcode-cn.com/problems/group-anagrams/
    vector<string> groupAnaVec = {"eat", "tea", "tan", "ate", "nat", "bat"};
    GroupAnagramsSolution *groupAnaSln = new GroupAnagramsSolution();
    groupAnaSln->groupAnagrams(groupAnaVec);
    delete[] groupAnaSln;

    // 最大子序和 https://leetcode-cn.com/problems/maximum-subarray
    MaxSubArraySolution *maxSubArrSln = new MaxSubArraySolution();
    vector<int> maxSubArrVec = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    maxSubArrSln->maxSubArrayDP(maxSubArrVec);
    delete[] maxSubArrSln;

    // 跳跃游戏 https://leetcode-cn.com/problems/jump-game/
    CanJumpSolution *canJumpSln = new CanJumpSolution();
    vector<int> canJumpVec = {2, 0, 1, 0, 1};
    bool canJumpFlag = canJumpSln->canJump(canJumpVec);
    delete[] canJumpSln;

    // 合并区间 https://leetcode-cn.com/problems/merge-intervals/
    MergeIntervalSolution *mergeIntervalSln = new MergeIntervalSolution();
    vector<vector<int>> mergeIntervalVec;
    vector<int> mergeIntervalVec1 = {1, 3};
    vector<int> mergeIntervalVec2 = {2, 6};
    vector<int> mergeIntervalVec3 = {8, 11};
    mergeIntervalVec.push_back(mergeIntervalVec1);
    mergeIntervalVec.push_back(mergeIntervalVec2);
    mergeIntervalVec.push_back(mergeIntervalVec3);
    mergeIntervalSln->merge(mergeIntervalVec);
    delete[] mergeIntervalSln;

    // 不同路径 https://leetcode-cn.com/problems/unique-paths/
    UniquePathSolution *uniPathSln = new UniquePathSolution();
    uniPathSln->uniquePaths(23, 12);
    delete[] uniPathSln;

    // 最小路径和 https://leetcode-cn.com/problems/minimum-path-sum/
    MinPathSumSolution *minPathSumSln = new MinPathSumSolution();
    vector<vector<int>> minPathSumVec;
    vector<int> minPathSumVec1 = {1, 3, 1};
    vector<int> minPathSumVec2 = {1, 5, 1};
    vector<int> minPathSumVec3 = {4, 2, 1};
    minPathSumVec.push_back(minPathSumVec1);
    minPathSumVec.push_back(minPathSumVec2);
    minPathSumVec.push_back(minPathSumVec3);
    minPathSumSln->minPathSum(minPathSumVec);
    delete[] minPathSumSln;

    // 爬楼梯 https://leetcode-cn.com/problems/climbing-stairs/
    ClimbStairSolution *climbStairSln = new ClimbStairSolution();
    climbStairSln->climbStairs(3);
    delete[] climbStairSln;

    // 编辑距离 https://leetcode-cn.com/problems/edit-distance/
    MinDistanceSolution *minDistanceSln = new MinDistanceSolution();
    int minDistance = minDistanceSln->minDistance("horse", "ros");
    delete[] minDistanceSln;

    // 颜色分类 https://leetcode-cn.com/problems/sort-colors/
    SortColorSolution *sortColorSln = new SortColorSolution();
    vector<int> sortColorVec = {2, 2, 1, 0, 0, 1, 2, 2};
    sortColorSln->sortColors(sortColorVec);
    delete[] sortColorSln;

    // 最小覆盖子串 https://leetcode-cn.com/problems/minimum-window-substring/
    MinWindowSolution *minWindowSln = new MinWindowSolution();
    string minWindowStr = minWindowSln->minWindow("ADOBECODEBANC", "ABC");
    delete[] minWindowSln;

    // 子集 https://leetcode-cn.com/problems/subsets/
    SubsetSolution *subsetSln = new SubsetSolution();
    vector<int> subsetVec = {1, 2, 3};
    vector<vector<int>> subsetVecRes = subsetSln->subsets(subsetVec);
    delete[] subsetSln;

    // 单词搜索 https://leetcode-cn.com/problems/word-search/
    WordExistSolution *wordExistSln = new WordExistSolution();
    vector<vector<char>> wordExistVec;
    vector<char> wordExistVec1 = {'A', 'B', 'C', 'E'};
    vector<char> wordExistVec2 = {'S', 'F', 'C', 'S'};
    vector<char> wordExistVec3 = {'A', 'D', 'E', 'E'};
    wordExistVec.push_back(wordExistVec1);
    wordExistVec.push_back(wordExistVec2);
    wordExistVec.push_back(wordExistVec3);
    wordExistSln->exist(wordExistVec, "ABCCED");
    delete[] wordExistSln;

    // 最大矩形 https://leetcode-cn.com/problems/maximal-rectangle/
    MaxRecSolution *maxRecSln = new MaxRecSolution();
    vector<vector<char>> maxRecVec;
    vector<char> maxRecVec1 = {'1', '0', '1', '0', '0'};
    vector<char> maxRecVec2 = {'1', '0', '1', '1', '1'};
    vector<char> maxRecVec3 = {'1', '1', '1', '1', '1'};
    vector<char> maxRecVec4 = {'1', '0', '0', '1', '0'};
    maxRecVec.push_back(maxRecVec1);
    maxRecVec.push_back(maxRecVec2);
    maxRecVec.push_back(maxRecVec3);
    maxRecVec.push_back(maxRecVec4);
    maxRecSln->maximalRectangle(maxRecVec);
    delete[] maxRecSln;

    // 二叉树的中序遍历 https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
    // 前序遍历规则：根结点 ---> 左子树 ---> 右子树
    // 中序遍历规则：左子树---> 根结点 ---> 右子树
    // 后序遍历规则：左子树 ---> 右子树 ---> 根结点
    InorderTraversalSolution *inorderTraversalSln = new InorderTraversalSolution();
    TreeNode *nodeRL = new TreeNode(3);
    TreeNode *nodeR = new TreeNode(2);
    nodeR->left = nodeRL;
    TreeNode *node = new TreeNode(1);
    node->right = nodeR;
    inorderTraversalSln->inorderTraversal(node);
    delete[] nodeRL;
    delete[] nodeR;
    delete[] node;
    delete[] inorderTraversalSln;

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
    BuildTreeSolution *buildTreeSln = new BuildTreeSolution();
    vector<int> preOrder = {3,9,20,15,7};
    vector<int> inOrder = {9,3,15,20,7};
    TreeNode *root = buildTreeSln->buildTree(preOrder, inOrder);
    delete[] buildTreeSln;

    // 二叉树展开为链表 https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/
    FlattenSolution *flattenSln = new FlattenSolution();
    TreeNode *flattenNode = new TreeNode(3);
    TreeNode *flattenNodeL = new TreeNode(9);
    TreeNode *flattenNodeR = new TreeNode(20);
    TreeNode *flattenNodeRL = new TreeNode(15);
    TreeNode *flattenNodeRR = new TreeNode(7);
    flattenNode->left = flattenNodeL;
    flattenNode->right = flattenNodeR;
    flattenNodeR->left = flattenNodeRL;
    flattenNodeR->right = flattenNodeRR;
    flattenSln->flatten(flattenNode);
    delete [] flattenSln;

    return 0;
}
