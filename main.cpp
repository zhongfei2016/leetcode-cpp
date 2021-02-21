#include <iostream>

#include <algorithm>

#include "CommonUtils.h"
#include "SolutionLengthOfLongestSubstring.h"
#include "SolutionCountSmaller.h"
#include "string/SolutionLongestPalindrome.h"
#include "string/LongestPalindromeSln.hpp"
#include "string/RestoreIPAddrSln.hpp"
#include "string/NumConvertSln.h"
#include "string/StringConvertSln.h"
#include "string/MaxSameStrSln.h"
#include "string/MaxUnduplicateStrSln.h"
#include "string/ValidIPAddrSln.h"
#include "regex/SolutionPatternMatch.h"
#include "SolutionMaxArea.h"
#include "SolutionThreeSum.h"
#include "LetterCombiSolution.h"
#include "SolutionBracketValid.h"
#include "GenerateBacktraceSolution.h"
#include "list/MergeKListsSolution.h"
#include "LongValidBracketSolution.h"
#include "SearchSolution.h"
#include "SearchRangeSolution.h"
#include "TrapSolution.h"
#include "dfs/PermuteSolution.h"
#include "dfs/PermuteSolutionII.h"
#include "dfs/CombinationSumSolution.h"
#include "dfs/NextPermutationSolution.h"
#include "dfs/FindTargetSumSln.h"
#include "dfs/CombinationSumIISln.h"
#include "bfs/WordBreakIIBfsSln.h"
#include "bfs/OrangeRotSln.h"
#include "bfs/WaterMeasureSln.hpp"
#include "bfs/WaterMeasureSln2.hpp"
#include "bfs/ShortestDistanceSln.hpp"
#include "bfs/NumBusToDestSln.hpp"
#include "bfs/LadderLengthSln.hpp"
#include "bfs/WordBreakBfsSln.hpp"
#include "bfs/RescueSln.h"
#include "bfs/NoiseCalSln.h"
#include "bfs/ShortestPathSln.h"
#include "RotateSolution.h"
#include "GroupAnagramsSolution.h"
#include "MaxSubArraySolution.h"
#include "CanJumpSolution.h"
#include "MergeIntervalSolution.h"
#include "UniquePathSolution.h"
#include "dp/MinPathSumSolution.h"
#include "dp/MinDistanceSolution.h"
#include "dp/CoinChangeSln.h"
#include "dp/CoinChangeIISln.h"
#include "dp/MinCostTicketsSln.h"
#include "dp/NumTreesSolution.h"
#include "dp/UniquePathWithObstacleSln.h"
#include "dp/CountSubstrSln.h"
#include "dp/LongestPalindromeSequenceSln.h"
#include "dp/YangHuiTriangleSln.hpp"
#include "ClimbStairSolution.h"
#include "DoublePoint/SortColorSolution.h"
#include "MinWindowSolution.h"
#include "SubsetSolution.h"
#include "WordExistSolution.h"
#include "MaxRecSolution.h"
#include "tree/InorderTraversalSolution.h"
#include "tree/ValidBSTSolution.h"
#include "tree/SymmetricSolution.h"
#include "tree/LevelOrderSolution.h"
#include "tree/MaxDepthSolution.h"
#include "tree/BuildTreeSolution.h"
#include "tree/FlattenSolution.h"
#include "MaxProfitSolution.h"
#include "hash/LongestConsecutiveSln.h"
#include "hash/UndergroundSystem.h"
#include "WordBreakSln.h"
#include "LuckFibonacciStrSln.h"
#include "list/HasCycleSln.h"
#include "list/RotateListNodeSln.hpp"
#include "list/ReverseListSln.hpp"
#include "LRU/LRUCache.h"
#include "IncDecArraySln.h"
#include "array/CenterIndexSln.h"
#include "array/DominantIndexSln.h"
#include "array/RemoveElementSln.h"
#include "array/PlusOneSln.h"
#include "array/RotateSln.hpp"
#include "string/AddBinarySln.h"
#include "UnionFound/UnionFoundSln.hpp"
#include "greedy/DivideChocolateSln.hpp"
#include "greedy/FindMinArrowShotSln.h"
#include "topology/FindCourseOrderSln.hpp"
#include "topology/CanFinCourseSln.hpp"
#include "topology/SeqReconstructSln.hpp"
#include "topology/AlienOrderSln.h"
#include "SlideWindow/EqualSubStrSln.hpp"
#include "SlideWindow/MinSubArrayLenSln.h"
#include "PrefixSumHash/SubArraySumSln.hpp"
#include "PrefixSumHash/CheckSubArraySumSln.hpp"
#include "diff/CarPoolingSln.hpp"
#include "trie/MinLengthEncodeSln.hpp"
#include "trie/ReplaceWordsSln.hpp"
#include "trie/Trie.hpp"
#include "dichotomy/SearchMatrixSln.hpp"
#include "dichotomy/SolutionFindMedianSortedArrays.h"
#include "dichotomy/SnowMountainSln.h"
#include "dichotomy/ReversePairSln.h"
#include "operation/SuffixOperationSln.h"
#include "queue/PriorityQueueSln.h"
#include "queue/RerangeStrSln.h"
#include "queue/TaskScheduleSln.h"
#include "queue/ReorganizeStrSln.h"
#include "stack/DailyTempSln.h"
#include "stack/FindLenOfLCISSln.h"
#include "stack/MaxNumSln.h"
#include "stack/MostCompetitiveSln.h"

int main() {
    // 最长不重复子串 https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
    string str = "abcabdcdd";
    SolutionLengthOfLongestSubstring *lols = new SolutionLengthOfLongestSubstring();
    int maxLen = lols->lengthOfLongestSubstring(str);
    delete[] lols;

    // 计算右侧小于当前元素的个数 https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/
    std::vector<int> nums = {5, 3, 6, 1};
    SolutionCountSmaller cs;
    vector<int> calNums = cs.countSmaller(nums);
    for (int i = 0; i < calNums.size(); i++) {
        cout << calNums[i] << endl;
    }
    nums = {5, 3, 6, 1};
    calNums = cs.countSmaller2(nums);

    // 两数组中位数 https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
    std::vector<int> nums1 = {5, 3, 6, 1};
    std::vector<int> nums2 = {2, 4};
    SolutionFindMedianSortedArrays fmsa;
    double fmsaRes = fmsa.findMedianSortedArrays(nums1, nums2);
    double fmsaRes2 = fmsa.findMedianSortedArrays2(nums1, nums2);
    cout << fmsaRes << "," << fmsaRes2 << endl;

    // 最长回文子串 https://leetcode-cn.com/problems/longest-palindromic-substring/
    SolutionLongestPalindrome *lp = new SolutionLongestPalindrome();
    lp->longestPalindrome("aaaa");
    delete[] lp;

    // 最长回文串 取给定字符串的字符凑最长回文串 https://leetcode-cn.com/problems/longest-palindrome/
    LongestPalindromeSln longestPalindromeSln;
    longestPalindromeSln.longestPalindrome("abccccdd");

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
    NextPermutationSolution nps;
    vector<int> npsVec = {1, 3, 2, 4};
    nps.nextPermutation(npsVec);
    npsVec = {1, 2, 3, 4, 6, 5};
    nps.nextPermutation2(npsVec);
    npsVec = {1, 2, 3, 4, 5, 6};
    vector<vector<int>> npsVesRes;
    while (npsVec[0] != 6) {
        nps.nextPermutation3(npsVec);
        npsVesRes.push_back(npsVec);
    }
    int npsVesResSize = npsVesRes.size();

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

    CombinationSumIISln combinationSumIiSln;
    vector<int> cssVec2 = {2, 5, 2, 1, 2};
    combinationSumIiSln.combinationSum2(cssVec2, 5);

    // 接雨水 https://leetcode-cn.com/problems/trapping-rain-water/
    TrapSolution *trapSln = new TrapSolution();
    vector<int> trapSlnVec = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    trapSln->trap(trapSlnVec);
    delete[] trapSln;

    // 全排列 https://leetcode-cn.com/problems/permutations/
    PermuteSolution permuteSln;
    vector<int> premuteSlnVec = {1, 2, 3};
    permuteSln.permute(premuteSlnVec);

    // 全排列2 https://leetcode-cn.com/problems/permutations-ii/
    PermuteSolutionII permuteSlnII;
    vector<int> permuteSlnIIVec = {3, 3, 0, 3};
    permuteSlnII.permuteUnique(permuteSlnIIVec);

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
    CanJumpSolution canJumpSln;
    vector<int> canJumpVec = {2, 0, 1, 0, 1};
    bool canJumpFlag = canJumpSln.canJump(canJumpVec);
    CommonUtils::ExpectFalse("CanJumpSolution", canJumpFlag);
    canJumpFlag = canJumpSln.canJump1(canJumpVec);
    CommonUtils::ExpectFalse("CanJumpSolution", canJumpFlag);
    canJumpVec = {0};
    canJumpFlag = canJumpSln.canJump1(canJumpVec);
    CommonUtils::ExpectFalse("CanJumpSolution", canJumpFlag);
    canJumpVec = {1, 2, 1, 1, 1};
//    canJumpVec = {5,3,1,1,4};
    canJumpVec = {1, 0, 0, 0, 0};
    int jumpSteps = canJumpSln.canJump2(canJumpVec);
    CommonUtils::ExpectEqual("CanJumpSolution", jumpSteps, 3);


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

    // 最大矩形面积
    MaxRecSolution maxRecSolution;
    vector<int> largestRectVec = {2, 1, 5, 6, 2, 3};
    maxRecSolution.largestRectangleArea(largestRectVec);

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
    maxRecSln->maximalRectangle2(maxRecVec);
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

    // 买股票最佳时机 https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
    MaxProfitSolution maxProfitSln;
    vector<int> maxProfitVec = {7, 1, 5, 3, 6, 4};
    maxProfitSln.maxProfit(maxProfitVec);

    // 最长连续序列 https://leetcode-cn.com/problems/longest-consecutive-sequence/
    LongestConsecutiveSln longestConsecutiveSln;
    vector<int> longestConsecutiveVec = {100, 4, 200, 1, 3, 2};
    longestConsecutiveSln.longestConsecutive(longestConsecutiveVec);

    // 单词拆分 动态规划 https://leetcode-cn.com/problems/word-break/
    WordBreakSln wordBreakSln;
    string wordBreakWord = "leetcode";
    vector<string> wordBreakDict = {"leet", "code"};
    wordBreakSln.wordBreak(wordBreakWord, wordBreakDict);

    // 环形链表 https://leetcode-cn.com/problems/linked-list-cycle/
    HasCycleSln hasCycleSln;
    ListNode *hasCycleNode1 = new ListNode(3);
    ListNode *hasCycleNode2 = new ListNode(2);
    ListNode *hasCycleNode3 = new ListNode(0);
    ListNode *hasCycleNode4 = new ListNode(-4);
    hasCycleNode1->next = hasCycleNode2;
    hasCycleNode2->next = hasCycleNode3;
    hasCycleNode3->next = hasCycleNode4;
    hasCycleNode4->next = hasCycleNode2;
    hasCycleSln.hasCycle(hasCycleNode1);

    // LRU缓存机制 least recently used https://leetcode-cn.com/problems/lru-cache/
    LRUCache cache(2 /* 缓存容量 */ );
    cache.put(1, 1);
    cache.put(2, 2);
    cache.get(1);
    cache.put(3, 3);
    cache.get(2);
    cache.put(4, 4);
    cache.get(1);
    cache.get(3);
    cache.get(4);

    // 符合斐波那契数列的子字符串
    LuckFibonacciStrSln luckFibonacciStrSln;
    luckFibonacciStrSln.ListLuckFiboSubStr("aabcd");

    // 零钱兑换 https://leetcode-cn.com/problems/coin-change/solution/
    CoinChangeSln coinChangeSln;
    vector<int> coinChangeVec = {2, 5, 10, 1};
    coinChangeSln.coinChange(coinChangeVec, 27);

    // 零钱兑换 II https://leetcode-cn.com/problems/coin-change-2/
    CoinChangeIISln coinChangeIISln;
    vector<int> coinChangeIIVec = {1, 2, 5};
    coinChangeIISln.change(5, coinChangeIIVec);

    // 最低票价 https://leetcode-cn.com/problems/minimum-cost-for-tickets/
    MinCostTicketsSln minCostTicketsSln;
    vector<int> minCostTicketsVec = {1, 4, 6, 7, 8, 20};
    vector<int> minCostTicketsCostsVec = {2, 7, 15};
    minCostTicketsSln.mincostTickets(minCostTicketsVec, minCostTicketsCostsVec);

    // 目标和 https://leetcode-cn.com/problems/target-sum/
    FindTargetSumSln findTargetSumSln;
    vector<int> findTargetSumVec = {1, 1, 1, 1, 1};
    findTargetSumSln.findTargetSumWays(findTargetSumVec, 3);

    // 不同路径 II https://leetcode-cn.com/problems/unique-paths-ii/
    UniquePathWithObstacleSln uniquePathWithObstacleSln;
    vector<vector<int>> uniPathObsVec = {{0, 0, 0},
                                         {0, 1, 0},
                                         {0, 0, 0}};
    std::cout << "UniquePathWithObstacleSln result: "
              << uniquePathWithObstacleSln.uniquePathsWithObstacles(uniPathObsVec) << std::endl;

    // 回文子串 https://leetcode-cn.com/problems/palindromic-substrings/
    CountSubstrSln countSubstrSln;
    countSubstrSln.countSubstrings("abc");

    // 最长回文子序列 https://leetcode-cn.com/problems/longest-palindromic-subsequence/
    LongestPalindromeSequenceSln longestPalindromeSequenceSln;
    longestPalindromeSequenceSln.longestPalindromeSubseq("bbbab");

    // 腐烂的橘子 https://leetcode-cn.com/problems/rotting-oranges/
    OrangeRotSln orangeRotSln;
    vector<vector<int>> orangeRotVec = {{1},
                                        {2},
                                        {1},
                                        {1}};
    orangeRotSln.orangesRotting(orangeRotVec);

    // 给定一个数组，如果去掉一个数后数组非严格单调增/减，则求出这个数，如果有多种方案，求最小值
    IncDecArraySln incDecArraySln;
    vector<int> incDecArrayVec = {5, 3, 4, 4, 5};
    incDecArraySln.GetIncDecNum(incDecArrayVec);

    // 寻找中位数 https://leetcode-cn.com/problems/find-pivot-index/
    CenterIndexSln centerIndexSln;
    vector<int> pivotIndexVec = {1, 2, 3};
    centerIndexSln.pivotIndex(pivotIndexVec);

    // 至少是其他数字两倍的最大数 https://leetcode-cn.com/problems/largest-number-at-least-twice-of-others/
    DominantIndexSln dominantIndexSln;
    vector<int> dominantIndexVec = {0, 0, 2, 3};
    dominantIndexSln.dominantIndex(dominantIndexVec);

    // 加一 https://leetcode-cn.com/problems/plus-one/
    PlusOneSln plusOneSln;
    vector<int> plusOneVec = {9, 9};
    plusOneSln.plusOne(plusOneVec);

    // 二进制求和 https://leetcode-cn.com/problems/add-binary/
    AddBinarySln addBinarySln;
    string addBinStr1 = addBinarySln.addBinary("101", "10111");
    string addBinStr2 = addBinarySln.addBinary(
            "10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101",
            "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011");
    vector<char> reverseVec = {'H'};
    // 使用双指针翻转字符串
    addBinarySln.reverseString(reverseVec);

    // 使用快慢双指针移除指定元素
    RemoveElementSln removeElementSln;
    vector<int> rmEleVec = {6, 1, 4, 5, 7, 6, 2, 6};
    removeElementSln.removeElement(rmEleVec, 6);

    // 旋转数组 https://leetcode-cn.com/problems/rotate-array/
    RotateSln rotateArrSln;
    vector<int> rotateArrVec = {1, 2, 3, 4, 5, 6, 7};
    rotateArrSln.rotate(rotateArrVec, 3);

    // 旋转链表
    RotateListNodeSln rotateListNodeSln;
    ListNode rotateListNode1(1);
    ListNode rotateListNode2(2);
    ListNode rotateListNode3(3);
    ListNode rotateListNode4(4);
    ListNode rotateListNode5(5);
    rotateListNode1.next = &rotateListNode2;
    rotateListNode2.next = &rotateListNode3;
    rotateListNode3.next = &rotateListNode4;
    rotateListNode4.next = &rotateListNode5;
    rotateListNodeSln.rotateRight(&rotateListNode1, 3);

    // 翻转链表
    ReverseListSln reverseListSln;
    ListNode reverseListNode1(1);
    ListNode reverseListNode2(2);
    ListNode reverseListNode3(3);
    ListNode reverseListNode4(4);
    ListNode reverseListNode5(5);
    reverseListNode1.next = &reverseListNode2;
    reverseListNode2.next = &reverseListNode3;
    reverseListNode3.next = &reverseListNode4;
    reverseListNode4.next = &reverseListNode5;
    reverseListSln.reverseList(&reverseListNode1);

    // 杨辉三角
    YangHuiTriangleSln yangHuiTriangleSln;
    yangHuiTriangleSln.generate(5);

    // 水壶问题
    WaterMeasureSln waterMeasureSln;
    waterMeasureSln.canMeasureWater(5, 3, 4);
    waterMeasureSln.canMeasureWater2(5, 3, 4);

    WaterMeasureSln2 waterMeasureSln2;
    waterMeasureSln2.canMeasureWater(5, 4, 3);

    // 离建筑物最近的距离 https://www.cnblogs.com/FdWzy/p/12382657.html
    ShortestDistanceSln shortestDistanceSln;
    vector<vector<int>> shortDistanceVec = {{1, 0, 2, 0, 1},
                                            {0, 0, 0, 0, 0},
                                            {0, 0, 1, 0, 0}};
    shortestDistanceSln.shortestDistance2(shortDistanceVec);

    // 公交路线 https://leetcode-cn.com/problems/bus-routes/
    NumBusToDestSln numBusToDestSln;
    vector<vector<int>> numBusToDestVec = {{1, 2, 7},
                                           {3, 6, 7}};
    numBusToDestSln.numBusesToDestination(numBusToDestVec, 1, 6);

    // 单词接龙 https://leetcode-cn.com/problems/word-ladder/
    LadderLengthSln ladderLengthSln;
    vector<string> ladderLengthWordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    ladderLengthSln.ladderLength("hit", "cog", ladderLengthWordList);

    // 单词拆分 https://leetcode-cn.com/problems/word-break/
    WordBreakBfsSln wordBreakBfsSln;
    vector<string> wordBreakBfsVec = {"leet", "code"};
    wordBreakBfsSln.wordBreak("leetcode", wordBreakBfsVec);

    RescueSln rescueSln;
    vector<vector<int>> rescueVec = {{0, 1, 0, 1, 0},
                                     {0, 0, 0, 0, 0}};
    rescueSln.rescue(rescueVec, 0, 0, 0, 4);
    // 并查集 朋友圈 https://leetcode-cn.com/problems/friend-circles/
    UnionFoundSln unionFoundSln;
    vector<vector<int>> unionFoundVec = {{1, 0, 0, 1},
                                         {0, 1, 1, 0},
                                         {0, 1, 1, 1},
                                         {1, 0, 1, 1}};
    unionFoundSln.findCircleNum(unionFoundVec);

    // 贪心算法 分享巧克力 https://www.cnblogs.com/slowbirdoflsh/p/11738134.html
    DivideChocolateSln divideChocolateSln;
    vector<int> divideChocolateVec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    divideChocolateSln.maximizeSweetness2(divideChocolateVec, 5);
    divideChocolateVec = {2, 2, 2, 2, 2};
    divideChocolateSln.maximizeSweetness(divideChocolateVec, 1);

    // 拓扑排序 课程表II https://leetcode-cn.com/problems/course-schedule-ii/
    FindCourseOrderSln findCourseOrderSln;
    vector<vector<int>> findCourseVec = {{1, 0},
                                         {2, 0},
                                         {3, 1},
                                         {3, 2}};
    findCourseOrderSln.findOrder(4, findCourseVec);

    // 滑动窗口 尽可能使字符串相等 https://leetcode-cn.com/problems/get-equal-substrings-within-budget/
    EqualSubStrSln equalSubStrSln;
    equalSubStrSln.equalSubstring("pxezla", "loewbi", 25);

    // 拓扑排序 课程表I https://leetcode-cn.com/problems/course-schedule/
    CanFinCourseSln canFinCourseSln;
    vector<vector<int>> canFinCourseVec = {{1, 0},
                                           {2, 0},
                                           {3, 1},
                                           {3, 2}};
    canFinCourseSln.canFinish(4, canFinCourseVec);

    SeqReconstructSln seqReconstructSln;
    vector<int> seqReconstructOrg = {4, 1, 5, 2, 6, 3};
    vector<vector<int>> seqReconstructSeqs = {{5, 2, 6, 3},
                                              {4, 1, 5, 2}};
    seqReconstructSln.sequenceReconstruction(seqReconstructOrg, seqReconstructSeqs);

    // 前缀和Hash 和为K的子数组 https://leetcode-cn.com/problems/subarray-sum-equals-k/
    SubArraySumSln subArraySumSln;
    vector<int> subArraySumVec = {1, 5, 4, 3, 6, 2, 8, 6};
    subArraySumSln.subarraySum2(subArraySumVec, 10);

    // 连续子数组的和 https://leetcode-cn.com/problems/continuous-subarray-sum/
    CheckSubArraySumSln checkSubArraySumSln;
    vector<int> checkSubArraySumVec = {23, 2, 4, 6, 7};
    checkSubArraySumSln.checkSubarraySum(checkSubArraySumVec, 6);

    // 拼车 差分 1094
    CarPoolingSln carPoolingSln;
    vector<vector<int>> carPoolTrip = {{3, 2, 7},
                                       {3, 7, 9},
                                       {8, 3, 9}};
    carPoolingSln.carPooling(carPoolTrip, 11);

    // 单词的压缩编码 820 拓扑排序
    MinLengthEncodeSln minLengthEncodeSln;
    vector<string> minLenEncodeVec = {"time", "me", "bell"};
    minLengthEncodeSln.minimumLengthEncoding(minLenEncodeVec);

    // 单词替换 拓扑排序 https://leetcode-cn.com/problems/replace-words/
    ReplaceWordsSln replaceWordsSln;
    vector<string> replaceWordVec = {"cat", "bat", "rat"};
    replaceWordsSln.replaceWords(replaceWordVec, "the cattle was rattled by the battery");

    // 复原IP地址，dfs深度遍历 https://leetcode-cn.com/problems/restore-ip-addresses/
    RestoreIPAddrSln restoreIpAddrSln;
    restoreIpAddrSln.restoreIpAddresses("25525511135");

    NumConvertSln numConvertSln;
    numConvertSln.NumConvertTest();

    StringConvertSln stringConvertSln;
    stringConvertSln.StringConvertTest();

    SearchMatrixSln searchMatrixSln;
    vector<vector<int>> searchMatrixVec = {{1,  4,  7,  11, 15},
                                           {2,  5,  8,  12, 19},
                                           {3,  6,  9,  16, 22},
                                           {10, 13, 14, 17, 24},
                                           {18, 21, 23, 26, 30}
    };
    searchMatrixSln.searchMatrix(searchMatrixVec, 5);

    MinSubArrayLenSln minSubArrayLenSln;
    vector<int> minSubArrayLenVec = {1, 2, 1, 3, 4};
    minSubArrayLenSln.minSubArrayLen(7, minSubArrayLenVec);

    FindMinArrowShotSln findMinArrowShotSln;
    vector<vector<int>> findMinArrowShotVec = {{10, 16},
                                               {2,  8},
                                               {1,  6},
                                               {7,  12}};
    findMinArrowShotSln.findMinArrowShots(findMinArrowShotVec);
    findMinArrowShotVec = {{2, 3},
                           {2, 3}};
    findMinArrowShotSln.findMinArrowShots(findMinArrowShotVec);
    findMinArrowShotVec = {{3, 9},
                           {7, 12},
                           {3, 8},
                           {6, 8},
                           {9, 10},
                           {2, 9},
                           {0, 9},
                           {3, 9},
                           {0, 6},
                           {2, 8}};
    findMinArrowShotSln.findMinArrowShots(findMinArrowShotVec);
    findMinArrowShotVec = {{9, 17},
                           {4, 12},
                           {4, 8},
                           {4, 8},
                           {7, 13},
                           {3, 4},
                           {7, 12},
                           {9, 15}};
    findMinArrowShotSln.findMinArrowShots(findMinArrowShotVec);

    // 中缀表达式转成后缀表达式并计算结果
    SuffixOperationSln suffixOperationSln;
    double resultSuffix = suffixOperationSln.CalOperation("1+((21+315)*40)-15");

    // 优先级队列
    PriorityQueueSln priorityQueueSln;
    priorityQueueSln.PriorityQueueTest();

    // 最长不含重复字符的子字符串
    MaxUnduplicateStrSln maxUnduplicateStrSln;
    maxUnduplicateStrSln.lengthOfLongestSubstring("bbbbb");

    MaxSameStrSln maxSameStrSln;
    maxSameStrSln.maxSameStr("abcadgbcs", "vavcadgbccacsvb");

    NoiseCalSln noiseCalSln;
    noiseCalSln.calculateNoise(5, 6, {{3, 4, 3},
                                      {1, 1, 4}});

    RerangeStrSln rerangeStrSln;
    rerangeStrSln.rearrangeString("aabbcc", 3);

    SnowMountainSln snowMountainSln;
//    int mountainCost = snowMountainSln.snowMountainCost({5,1,4,3,8},3);
    int mountainCost = snowMountainSln.snowMountainCost({1, 2, 99999, 3, 100000}, 3);

    TaskScheduleSln taskScheduleSln;
    taskScheduleSln.leastInterval({'A', 'A', 'A', 'B', 'B', 'B'}, 2);

    ReorganizeStrSln reorganizeStrSln;
    reorganizeStrSln.reorganizeString("aab");

    ShortestPathSln shortestPathSln;
    shortestPathSln.shortestPath({{0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1},
                                  {0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1},
                                  {1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0},
                                  {1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1},
                                  {1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1},
                                  {0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1},
                                  {0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1},
                                  {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0},
                                  {0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0},
                                  {0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
                                  {0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0}}, 27);

    WordBreakIIBfsSln wordBreakIiBfsSln;
    wordBreakIiBfsSln.wordBreak("catsanddog", {"cat", "cats", "and", "sand", "dog"});

    set<int> testSet = {0, 0, 1, 2, 0, 4, 6, 8, 0, 0, 0, 9, 10, 0};
    for (auto iter = testSet.begin(); iter != testSet.end();) {
        if (*iter == 0) {
            iter = testSet.erase(iter);
        } else {
            iter++;
        }
    }
    for (auto item : testSet) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    vector<int> testVector = {0, 0, 1, 2, 0, 4, 6, 8, 0, 0, 0, 9, 10, 0};
    for (auto iter = testVector.begin(); iter != testVector.end();) {
        if (*iter == 0) {
            iter = testVector.erase(iter);
        } else {
            iter++;
        }
    }
    for (auto item : testVector) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    std::map<int, int> testMap = {{1, 9},
                                  {2, 5},
                                  {0, 1},
                                  {5, 8},
                                  {3, 9},
                                  {0, 1},
                                  {2, 7},
                                  {4, 5},
                                  {1, 0}};
//    for (auto iter = testMap.begin(); iter != testMap.end();iter++) {
//        if (iter->first < 4) {
//            testMap.erase(iter);
//        }
//    }
    for (auto item : testMap) {
        std::cout << item.first << ":" << item.second << std::endl;
    }

    DailyTempSln dailyTempSln;
    vector<int> dailyTempVec = {73, 74, 75, 71, 69, 72, 76, 73};
    dailyTempSln.dailyTemperatures(dailyTempVec);

    FindLenOfLCISSln findLenOfLcisSln;
    vector<int> findLenOfLcisVec = {1, 3, 5, 4, 7};
    findLenOfLcisSln.findLengthOfLCIS(findLenOfLcisVec);

    MaxNumSln maxNumSln;
    maxNumSln.maxNumber({3, 4, 6, 5}, {9, 1, 2, 5, 8, 3}, 5);
    maxNumSln.maxNumber({6, 7}, {6, 0, 4}, 5);

    MostCompetitiveSln mostCompetitiveSln;
    vector<int> mostCompetitiveVec = {3, 5, 2, 6};
    mostCompetitiveSln.mostCompetitive(mostCompetitiveVec, 2);

    ReversePairSln reversePairSln;
    vector<int> reversePairVec = {7, 5, 6, 4};
    int reverseNum = reversePairSln.reversePairs(reversePairVec);

    UndergroundSystem undergroundSystem;
    undergroundSystem.checkIn(45, "Leyton", 3);
    undergroundSystem.checkIn(32, "Paradise", 8);
    undergroundSystem.checkIn(27, "Leyton", 10);
    undergroundSystem.checkOut(45, "Waterloo", 15);
    undergroundSystem.checkOut(27, "Waterloo", 20);
    undergroundSystem.checkOut(32, "Cambridge", 22);
    undergroundSystem.getAverageTime("Paradise",
                                     "Cambridge");       // 返回 14.0。从 "Paradise"（时刻 8）到 "Cambridge"(时刻 22)的行程只有一趟
    undergroundSystem.getAverageTime("Leyton",
                                     "Waterloo");          // 返回 11.0。总共有 2 躺从 "Leyton" 到 "Waterloo" 的行程，编号为 id=45 的乘客出发于 time=3 到达于 time=15，编号为 id=27 的乘客于 time=10 出发于 time=20 到达。所以平均时间为 ( (15-3) + (20-10) ) / 2 = 11.0
    undergroundSystem.checkIn(10, "Leyton", 24);
    undergroundSystem.getAverageTime("Leyton", "Waterloo");          // 返回 11.0
    undergroundSystem.checkOut(10, "Waterloo", 38);
    undergroundSystem.getAverageTime("Leyton", "Waterloo");          // 返回 12.0

    ValidIPAddrSln validIpAddrSln;
    validIpAddrSln.validIPAddress("172.16.254.1");
    validIpAddrSln.validIPAddress("2001:0db8:85a3:0000:0000:8a2e:0370:7334");

    AlienOrderSln alienOrderSln;
    vector<string> alienWords = {"wrt", "wrf", "er", "ett", "rftt"};
    alienOrderSln.alienOrder(alienWords);
    return 0;
}
