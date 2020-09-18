//
// Created by ZHONGFEI on 2020/9/18.
//

#ifndef LEETCODE_CPP_RESCUESLN_H
#define LEETCODE_CPP_RESCUESLN_H

#include <vector>

using namespace std;

class RescueSln {
public:
    int rescue(vector<vector<int>> &path, int startX, int startY, int endX, int endY);

    int TryNextStatus(int posX,int posY,bool usePrivilege, int step);


#endif //LEETCODE_CPP_RESCUESLN_H
