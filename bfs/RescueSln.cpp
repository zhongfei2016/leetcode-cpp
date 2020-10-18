//
// Created by ZHONGFEI on 2020/9/18.
//

#include "RescueSln.h"

vector<vector<bool>> usedPrivileges;
vector<vector<bool>> noUsedPrivileges;

int RescueSln::rescue(vector<vector<int> > &path, int startX, int startY, int endX, int endY) {
    int width = path.size();
    int height = path[0].size();
    usedPrivileges.resize(width, vector<bool>(height));
    noUsedPrivileges.resize(width, vector<bool>(height));

    queue<Status> que;
    que.emplace(startX, startY, false, 0);
    while (!que.empty()) {
        auto &status = que.front();
        que.pop();
        if (status.posX == endX && status.posY == endY) {
            return status.step;
        }
        vector<vector<bool>> &visited = status.usePrivilege ? usedPrivileges : noUsedPrivileges;
        if (visited[status.posX][status.posY]) {
            continue;
        }
        if (status.posX < width - 1) {
            TryNextStatus(path, que, status, status.posX + 1, status.posY);
        }
        if (status.posX > 0) {
            TryNextStatus(path, que, status, status.posX - 1, status.posY);
        }
        if (status.posY < height - 1) {
            TryNextStatus(path, que, status, status.posX, status.posY + 1);
        }
        if (status.posY > 0) {
            TryNextStatus(path, que, status, status.posX, status.posY - 1);
        }
    }
    return -1;
}

void RescueSln::TryNextStatus(vector<vector<int>> &path, queue<Status> &que, Status &status, int nextPosX,
                              int nextPosY) {
    if (!status.usePrivilege && path[nextPosX][nextPosY] == 1) {
        que.emplace(Status(nextPosX, nextPosY, true, status.step + 1));
        usedPrivileges[status.posX][status.posY] = true;
    } else if (path[nextPosX][nextPosY] == 0) {
        que.emplace(Status(nextPosX, nextPosY, status.usePrivilege, status.step + 1));
        vector<vector<bool>> &visited = status.usePrivilege ? usedPrivileges : noUsedPrivileges;
        visited[status.posX][status.posY] = true;
    }
}