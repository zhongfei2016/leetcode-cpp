//
// Created by ZHONGFEI on 2021/3/26.
//
#include "UnionFoundSln.hpp"
#include "MakeConnectedSln.h"
#include <vector>

using namespace std;

int main() {
    // 并查集 朋友圈 https://leetcode-cn.com/problems/friend-circles/
    UnionFoundSln unionFoundSln;
    vector<vector<int>> unionFoundVec = {{1, 0, 0, 1},
                                         {0, 1, 1, 0},
                                         {0, 1, 1, 1},
                                         {1, 0, 1, 1}};
    unionFoundSln.findCircleNum(unionFoundVec);

    vector<vector<int>> connections = {{0, 1},
                                       {0, 2},
                                       {1, 2}};
    MakeConnectedSln makeConnectedSln;
    makeConnectedSln.makeConnected(4, connections);
    return 0;
}