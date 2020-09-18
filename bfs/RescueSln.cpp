//
// Created by ZHONGFEI on 2020/9/18.
//

#include "RescueSln.h"

#include <queue>

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

int RescueSln::rescue(vector<vector<int> > &path, int startX, int startY, int endX, int endY) {
    vector<vector<int>> usedPrivileges(path.size(), vector<int>(path[0].size()));
    vector<vector<int>> noUsedPrivileges(path.size(), vector<int>(path[0].size()));

    int width = path.size();
    int height = path[0].size();
    queue<Status> que;
    que.emplace(startX, startY, false, 0);
    while (!que.empty()) {
        auto &status = que.back();
        if (status.posX == endX && status.posY == endY) {
            return status.step;
        }
        if (status.posX < width - 1) {
            TryNextStatus(status.posX + 1, status.posX, status.usePrivilege, status.step + 1);
        }
    }
    return -1;
}

int RescueSln::TryNextStatus(int posX, int posY, bool usePrivilege, int step) {

}