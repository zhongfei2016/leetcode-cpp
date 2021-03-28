//
// Created by ZHONGFEI on 2021/3/26.
//
#include "common/CommonUtils.h"
#include "CanJumpSolution.h"
#include "DivideChocolateSln.hpp"
#include "FindMinArrowShotSln.h"
#include "AdvantageCountSln.h"

int main() {
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

    // 贪心算法 分享巧克力 https://www.cnblogs.com/slowbirdoflsh/p/11738134.html
    DivideChocolateSln divideChocolateSln;
    vector<int> divideChocolateVec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    divideChocolateSln.maximizeSweetness2(divideChocolateVec, 5);
    divideChocolateVec = {2, 2, 2, 2, 2};
    divideChocolateSln.maximizeSweetness(divideChocolateVec, 1);

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

    AdvantageCountSln advantageCountSln;
    vector<int> advantageVecA = {12,24,8,32};
    vector<int> advantageVecB = {13,25,32,11};
    advantageCountSln.advantageCount(advantageVecA, advantageVecB);
    return 0;
}