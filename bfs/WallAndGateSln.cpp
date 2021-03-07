//
// Created by ZHONGFEI on 2021/3/3.
// 墙与门 https://www.cnblogs.com/grandyang/p/5285868.html
//

#include "WallAndGateSln.h"

#include <queue>

struct node {
    int x, y;
    int dis;
};

void bfs(int sx, int sy, vector<vector<int>> &rooms) {
    int dir[][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
    int m = rooms.size(), n = rooms[0].size();
    queue<node> Queue;
    node start;
    start.x = sx, start.y = sy;
    start.dis = 0;
    Queue.push(start);
    while (!Queue.empty()) {
        node cur = Queue.front();
        Queue.pop();
        node nex;
        for (int i = 0; i < 4; i++) {
            nex.x = cur.x + dir[i][0];
            nex.y = cur.y + dir[i][1];
            nex.dis = cur.dis + 1;
            if (nex.x < 0 || nex.x >= m || nex.y < 0 || nex.y >= n || rooms[nex.x][nex.y] <= 0 ||
                nex.dis >= rooms[nex.x][nex.y])
                continue;
            rooms[nex.x][nex.y] = min(rooms[nex.x][nex.y], nex.dis);
            Queue.push(nex);
        }

    }
}

void WallAndGateSln::wallsAndGates(vector<vector<int>> &rooms) {
    int m = rooms.size();
    if (m == 0) return;
    int n = rooms[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (rooms[i][j] == 0) {
                bfs(i, j, rooms);
            }
        }
    }

}

void WallAndGateSln::wallsAndGates3(vector<vector<int> > &rooms) {
    int m = rooms.size();
    if (m == 0) return;
    int n = rooms[0].size();
    queue<node> Queue;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (rooms[i][j] == 0) {
                node gate;
                gate.x = i, gate.y = j;
                gate.dis = 0;
                Queue.push(gate);
            }
        }
    }
    int dir[][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
    while (!Queue.empty()) {
        node cur = Queue.front();
        Queue.pop();
        node nex;
        for (int i = 0; i < 4; i++) {
            nex.x = cur.x + dir[i][0];
            nex.y = cur.y + dir[i][1];
            nex.dis = cur.dis + 1;
            if (nex.x < 0 || nex.x >= m || nex.y < 0 || nex.y >= n || rooms[nex.x][nex.y] <= 0 ||
                nex.dis >= rooms[nex.x][nex.y])
                continue;
            rooms[nex.x][nex.y] = min(rooms[nex.x][nex.y], nex.dis);
            Queue.push(nex);
        }

    }
}

void WallAndGateSln::wallsAndGates2(vector<vector<int> > &rooms) {
    queue<std::pair<int, int>> que;
    for (int i = 0; i < rooms.size(); i++) {
        for (int j = 0; j < rooms[0].size(); j++) {
            if (rooms[i][j] == 0) {
                que.push(std::make_pair(i, j));
            }
        }
    }
    vector<vector<int>> dirs = {{1,  0},
                                {-1, 0},
                                {0,  1},
                                {0,  -1}};
    while (!que.empty()) {
        auto item = que.front();
        int itemX = item.first;
        int itemY = item.second;
        que.pop();
        for (int i = 0; i < dirs.size(); i++) {
            int nextX = itemX + dirs[i][0];
            int nextY = itemY + dirs[i][1];
            if (nextX < 0 || nextX >= rooms.size() || nextY < 0 || nextY >= rooms[0].size() ||
                    rooms[nextX][nextY] < rooms[itemX][itemY] + 1) {
                continue;
            }
            rooms[nextX][nextY] = rooms[itemX][itemY] + 1;
            que.push(std::make_pair(nextX, nextY));
        }
    }


}

void WallAndGateSln::wallsAndGates4(vector<vector<int>> &rooms) {
    queue<pair<int, int>> q;
    vector<vector<int>> dirs{{0,  -1},
                             {-1, 0},
                             {0,  1},
                             {1,  0}};
    for (int i = 0; i < rooms.size(); ++i) {
        for (int j = 0; j < rooms[i].size(); ++j) {
            if (rooms[i][j] == 0) q.push({i, j});
        }
    }
    while (!q.empty()) {
        int i = q.front().first, j = q.front().second;
        q.pop();
        for (int k = 0; k < dirs.size(); ++k) {
            int x = i + dirs[k][0], y = j + dirs[k][1];
            if (x < 0 || x >= rooms.size() || y < 0 || y >= rooms[0].size() || rooms[x][y] < rooms[i][j] + 1) continue;
            rooms[x][y] = rooms[i][j] + 1;
            q.push({x, y});
        }
    }
};