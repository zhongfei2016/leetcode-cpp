//
// Created by ZHONGFEI on 2021/3/26.
//
#include "UnionFoundSln.hpp"
#include "MakeConnectedSln.h"
#include "RedudentConnectSln.h"
#include "RedudentConnectIISln.h"
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

    RedudentConnectSln redudentConnectSln;
    vector<vector<int>> redudentVec = {{1, 2},
                                       {1, 3},
                                       {2, 3}};
//    redudentConnectSln.findRedundantConnection(redudentVec);
    redudentVec = {{1, 2},
                   {2, 3},
                   {3, 4},
                   {1, 4},
                   {1, 5}};
    redudentConnectSln.findRedundantConnection(redudentVec);

    vector<vector<int>> redudentIIVec = {{2, 1},
                                         {3, 1},
                                         {4, 2},
                                         {1, 4}};
    RedudentConnectIISln redudentConnectIiSln;
    redudentConnectIiSln.findRedundantDirectedConnection(redudentIIVec);
    return 0;
}