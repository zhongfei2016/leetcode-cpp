//
// Created by ZHONGFEI on 2021/3/26.
//
#include "LetterCombiSolution.h"
#include "WordBreakIIBfsSln.h"
#include "OrangeRotSln.h"
#include "WaterMeasureSln.hpp"
#include "WaterMeasureSln2.hpp"
#include "ShortestDistanceSln.hpp"
#include "NumBusToDestSln.hpp"
#include "LadderLengthSln.hpp"
#include "WordBreakBfsSln.hpp"
#include "RescueSln.h"
#include "NoiseCalSln.h"
#include "ShortestPathSln.h"
#include "WallAndGateSln.h"

int main() {
    // 电话号码数字组合 https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
    LetterCombiSolution *lcs = new LetterCombiSolution();
    lcs->letterCombinations("23");
    delete[] lcs;

    // 腐烂的橘子 https://leetcode-cn.com/problems/rotting-oranges/
    OrangeRotSln orangeRotSln;
    vector<vector<int>> orangeRotVec = {{1},
                                        {2},
                                        {1},
                                        {1}};
    orangeRotSln.orangesRotting(orangeRotVec);

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
    rescueSln.rescue2(rescueVec, 0, 0, 0, 4);

    NoiseCalSln noiseCalSln;
    noiseCalSln.calculateNoise(5, 6, {{3, 4, 3},
                                      {1, 1, 4}});

    WallAndGateSln wallAndGateSln;
    vector<vector<int>> wallAndGateVec = {{INT_MAX, -1, 0,            INT_MAX},
                                          {INT_MAX, INT_MAX, INT_MAX, -1},
                                          {INT_MAX, -1,      INT_MAX, -1},
                                          {0,       -1,      INT_MAX, INT_MAX}};
    wallAndGateSln.wallsAndGates2(wallAndGateVec);
    return 0;
}