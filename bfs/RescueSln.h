//
// Created by ZHONGFEI on 2020/9/18.
//

#ifndef LEETCODE_CPP_RESCUESLN_H
#define LEETCODE_CPP_RESCUESLN_H

#include <vector>
#include <queue>

using namespace std;

class Status {
public:
    Status(int posX, int posY, bool usePrivilege, int step) {
        this->posX = posX;
        this->posY = posY;
        this->usePrivilege = usePrivilege;
        this->step = step;
    }

    int posX;
    int posY;
    bool usePrivilege;
    int step;
};

class RescueSln {
public:
    int rescue(vector<vector<int>> &path, int startX, int startY, int endX, int endY);

    void TryNextStatus(queue<Status> &que, vector<vector<bool>> &visited, int posX, int posY, bool usePrivilege, int step);
};

#endif //LEETCODE_CPP_RESCUESLN_H
