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

bool RescueSln::ProcessNextStep(vector<vector<int>> &path, queue<PathStep> &que, vector<vector<vector<bool>>> &visited, int endX, int endY) {
    vector<vector<int>> dirs = {{1,  0},
                                {-1, 0},
                                {0,  1},
                                {0,  -1}};
    auto item = que.front();
    que.pop();
    for (auto &dir : dirs) {
        int tempX = item.x + dir[0];
        int tempY = item.y + dir[1];
        if (tempX < 0 || tempX >= path.size() || tempY < 0 || tempY >= path[0].size()) {
            continue;
        }
        if (tempX == endX && tempY == endY) {
            return true;
        }
        if (path[tempX][tempY] == 1) {
            if (item.isPrivilege <= 0) {
                continue;
            } else {
                if (visited[tempX][tempY][item.isPrivilege - 1]) {
                    continue;
                }
                visited[tempX][tempY][item.isPrivilege - 1] = true;
                que.push({tempX, tempY, item.isPrivilege - 1});
            }
        } else {
            if (visited[tempX][tempY][item.isPrivilege]) {
                continue;
            }
            visited[tempX][tempY][item.isPrivilege] = true;
            que.push({tempX, tempY, item.isPrivilege});
        }
    }
    return false;
}

int RescueSln::rescue2(vector<vector<int> > &path, int startX, int startY, int endX, int endY) {
    int m = path.size();
    int n = path[0].size();
    vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(2, false)));
    queue<PathStep> que;
    que.push({startX, startY, 1});
    int step = 0;
    while (!que.empty()) {
        int size = que.size();
        step++;
        for (int i = 0; i < size; i++) {
            if (ProcessNextStep(path, que, visited, endX, endY)) {
                return step;
            }
        }
    }
    return -1;
}