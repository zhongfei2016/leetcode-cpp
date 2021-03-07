//
// Created by ZHONGFEI on 2020/9/18.
//

#ifndef LEETCODE_CPP_RESCUESLN_H
#define LEETCODE_CPP_RESCUESLN_H

#include <vector>
#include <queue>

using namespace std;

struct PathStep {
    PathStep(int x, int y, int isPrivilege) : x(x), y(y), isPrivilege(isPrivilege) {}

    int x;
    int y;
    int isPrivilege;
};

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

    int rescue2(vector<vector<int>> &path, int startX, int startY, int endX, int endY);

    void TryNextStatus(vector<vector<int> > &path, queue<Status> &que, Status &status, int nextPosX, int nextPosY);

    bool
    ProcessNextStep(vector<vector<int>> &path, queue<PathStep> &que, vector<vector<vector<bool>>> &visited, int endX,
                    int endY);
};

#endif //LEETCODE_CPP_RESCUESLN_H
