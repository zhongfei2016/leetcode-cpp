//
// Created by ZHONGFEI on 2020/9/18.
//

#include "RescueSln.h"

int RescueSln::rescue(vector<vector<int> > &path, int startX, int startY, int endX, int endY) {
    int width = path.size();
    int height = path[0].size();
    vector<vector<bool>> usedPrivileges(width, vector<bool>(height));
    vector<vector<bool>> noUsedPrivileges(width, vector<bool>(height));

    queue<Status> que;
    que.emplace(startX, startY, false, 0);
    while (!que.empty()) {
        auto &status = que.back();
        if (status.posX == endX && status.posY == endY) {
            return status.step;
        }
        vector<vector<bool>> &visited = status.usePrivilege ? usedPrivileges : noUsedPrivileges;
        if (visited[status.posX][status.posY]) {
            continue;
        }
        if (status.posX < width - 1) {
            TryNextStatus(que, visited, status.posX + 1, status.posY, status.usePrivilege, status.step + 1);
        }
        if (status.posX > 0) {
            TryNextStatus(que, visited, status.posX - 1, status.posY, status.usePrivilege, status.step + 1);
        }
        if (status.posY < height - 1) {
            TryNextStatus(que, visited, status.posX, status.posY + 1, status.usePrivilege, status.step + 1);
        }
        if (status.posY > 0) {
            TryNextStatus(que, visited, status.posX, status.posY - 1, status.usePrivilege, status.step + 1);
        }
    }
    return -1;
}

void RescueSln::TryNextStatus(queue<Status> &que, vector<vector<bool>> &visited, int posX, int posY, bool usePrivilege,
                             int step) {
    if (usePrivilege) {
        que.emplace(posX, posY, false, step);
    } else {
        que.emplace(posX, posY, true, step);
    }
    visited[posX][posY] = true;
}