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

    void TryNextStatus(vector<vector<int> > &path, queue<Status> &que, Status& status, int nextPosX, int nextPosY);
};

#endif //LEETCODE_CPP_RESCUESLN_H
