//
// Created by ZHONGFEI on 2021/3/26.
//
#include "SubsetSolution.h"
#include "WordExistSolution.h"
#include "GenerateBacktraceSolution.h"
#include "PermuteSolution.h"
#include "PermuteSolutionII.h"
#include "CombinationSumSolution.h"
#include "NextPermutationSolution.h"
#include "FindTargetSumSln.h"
#include "CombinationSumIISln.h"
#include "NumIsIslandSln.h"
#include "LargestIsLandSln.h"
#include "LandPeremiterSln.h"
#include "ExistPathSln.h"
#include "RedudentConnectSln.h"

int main() {
//给出 n 生成全部有效括号组合，回溯法 https://leetcode-cn.com/problems/generate-parentheses/
    GenerateBacktraceSolution gbs;
    gbs.generateParenthesis(3);

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

    // 组合总和 回溯算法 https://leetcode-cn.com/problems/combination-sum/
    CombinationSumSolution css;
    vector<int> cssVec = {4, 5, 6, 7, 7, 2};
    css.combinationSum(cssVec, 9);

    CombinationSumIISln combinationSumIiSln;
    vector<int> cssVec2 = {2, 5, 2, 1, 2};
    combinationSumIiSln.combinationSum2(cssVec2, 5);

    // 全排列 https://leetcode-cn.com/problems/permutations/
    PermuteSolution permuteSln;
    vector<int> premuteSlnVec = {1, 2, 3};
    permuteSln.permute(premuteSlnVec);

    // 全排列2 https://leetcode-cn.com/problems/permutations-ii/
    PermuteSolutionII permuteSlnII;
    vector<int> permuteSlnIIVec = {3, 3, 0, 3};
    permuteSlnII.permuteUnique(permuteSlnIIVec);

    ExistPathSln existPathSln;
    vector<vector<char>> existPathVec = {{'A', 'B', 'C', 'E'},
                                         {'S', 'F', 'C', 'S'},
                                         {'A', 'D', 'E', 'E'}};
    existPathSln.exist(existPathVec, "ABCCED");

    LandPeremiterSln landPeremiterSln;
    vector<vector<int>> landPeremiterVec = {{0, 1, 0, 0},
                                            {1, 1, 1, 0},
                                            {0, 1, 0, 0},
                                            {1, 1, 0, 0}};
    int landPeremiter = landPeremiterSln.islandPerimeter(landPeremiterVec);

    // 子集 https://leetcode-cn.com/problems/subsets/
    SubsetSolution subsetSln;
    vector<int> subsetVec = {1, 2, 3};
    vector<vector<int>> subsetVecRes = subsetSln.subsets(subsetVec);

    // 单词搜索 https://leetcode-cn.com/problems/word-search/
    WordExistSolution wordExistSln;
    vector<vector<char>> wordExistVec;
    vector<char> wordExistVec1 = {'A', 'B', 'C', 'E'};
    vector<char> wordExistVec2 = {'S', 'F', 'C', 'S'};
    vector<char> wordExistVec3 = {'A', 'D', 'E', 'E'};
    wordExistVec.push_back(wordExistVec1);
    wordExistVec.push_back(wordExistVec2);
    wordExistVec.push_back(wordExistVec3);
    wordExistSln.exist(wordExistVec, "ABCCED");

    // 目标和 https://leetcode-cn.com/problems/target-sum/
    FindTargetSumSln findTargetSumSln;
    vector<int> findTargetSumVec = {1, 1, 1, 1, 1};
    findTargetSumSln.findTargetSumWays(findTargetSumVec, 3);
    vector<vector<int>> redudentVec = {{1, 2},
                                       {2, 3},
                                       {3, 4},
                                       {1, 4},
                                       {1, 5}};
    RedudentConnectSln redudentConnectSln;
    redudentConnectSln.findRedundantConnection(redudentVec);
    return 0;
}