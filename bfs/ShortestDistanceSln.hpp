//
// leetcode-cpp
//
// 离建筑物最近的距离 https://www.cnblogs.com/FdWzy/p/12382657.html

#ifndef LEETCODE_CPP_SHORTESTDISTANCESLN_HPP
#define LEETCODE_CPP_SHORTESTDISTANCESLN_HPP
#include <climits>

//  离建筑物最近的距离 317
class ShortestDistanceSln {
public:
    int shortestDistance(vector<vector<int>> &grid);

    int shortestDistance2(vector<vector<int>> &grid);

};

int ShortestDistanceSln::shortestDistance(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    if (m == 0 or n == 0) { return 0; }
    vector<vector<int>> reached_buildings(m, vector<int>(n, 0));//记录有几个建筑物能到达当前位置
    vector<vector<int>> path_cnt(m, vector<int>(n, 0));//记录所有建筑物到当前位置的距离总和
    vector<vector<int>> dif = {{0,  1},
                               {0,  -1},
                               {1,  0},
                               {-1, 0}};
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int build_cnt = 0, res = INT32_MAX;
    bool flag = false;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] != 1) { continue; }
            build_cnt++;
            res = INT_MAX;
            queue<pair<int, int>> my_que;
            my_que.push({i, j});
            int cur_path_len = 1;
            while (not my_que.empty()) {
                int cur_siz = my_que.size();
                for (int k = 0; k < cur_siz; ++k) {
                    auto cur = my_que.front();
                    my_que.pop();
                    for (auto &d:dif) {
                        int x = cur.first + d[0], y = cur.second + d[1];
                        if (x >= 0 and x < m and y >= 0 and y < n and visited[x][y] == flag and grid[x][y] == 0) {
                            my_que.push({x, y});
                            visited[x][y] = !flag;
                            path_cnt[x][y] += cur_path_len;
                            reached_buildings[x][y] += 1;
                            if (reached_buildings[x][y] == build_cnt) {
                                res = min(res, path_cnt[x][y]);
                            }
                        }
                    }
                }
                cur_path_len++;
            }
            flag = !flag;
        }
    }
    return res == INT_MAX ? -1 : res;
}

/**
 * 如下，1是建筑物，0是可以通行的位置，2是障碍物
 * 1 - 0 - 2 - 0 - 1
 * 0 - 0 - 0 - 0 - 0
 * 0 - 0 - 1 - 0 - 0
 * @param grid
 * @return
 */
int ShortestDistanceSln::shortestDistance2(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    int buildCnt = 0;
    int minSteps = INT_MAX;
    // 统计可以到达该位置的建筑的个数
    vector<vector<int>> buildCntVec(m, vector<int>(n, 0));
    // 统计当前建筑物到当前位置所需的步数
    vector<vector<int>> buildStepsVec(m, vector<int>(n, 0));
    // 每次移动可以走的步数
    vector<vector<int>> steps = {{0,  1},
                                 {1,  0},
                                 {0,  -1},
                                 {-1, 0}};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // 不是1：建筑则跳过
            if (grid[i][j] != 1) {
                continue;
            }
            // 统计下当前的总建筑数
            buildCnt++;
            // 每一轮都要置位最小步数为最大值，即
            minSteps = INT_MAX;
            // 当前位置是1则以当前位置为起点遍历所有为0的位置
            // 统计从当前建筑开始的步数
            int curStep = 0;
            // 设置标志位数组标识以当前建筑为起点的这一轮走过的点，避免本轮重复走，本轮结束后要重新归位
            vector<vector<bool>> visit(m, vector<bool>(n, false));
            queue<pair<int, int>> que;
            que.push(make_pair(i, j));
            while (!que.empty()) {
                // 获取这一轮本次所需要遍历的可能的位置的个数
                int curQueSize = que.size();
                curStep++;
                // 当前这一轮本次的curQueSize种可能性
                for (int k = 0; k < curQueSize; k++) {
                    pair<int, int> curPos = que.front();
                    que.pop();
                    // 往四个方向各尝试走一步
                    for (auto step : steps) {
                        int x = curPos.first + step[0];
                        int y = curPos.second + step[1];
                        // 如果走了这一步后位置仍合法，且当前步在本轮未走过，且这一步是0，即是可以走的一步
                        if (x >= 0 && x < m && y >= 0 && y < n && visit[x][y] == false && grid[x][y] == 0) {
                            // 将这一步置为已走过，因为本轮不会再走了，直到换下一个起点
                            visit[x][y] = true;
                            // 把这一步作为起点加入队列
                            que.push(make_pair(x, y));
                            // 计算当前建筑到当前这个0位置的距离，并将每个0位对应的建筑数+1
                            buildCntVec[x][y]+=1;
                            buildStepsVec[x][y] += curStep;
                            // 以当前的总建筑数为目标统计最少步数
                            if (buildCntVec[x][y] == buildCnt) {
                                minSteps = min(minSteps, buildStepsVec[x][y]);
                            }
                        }
                    }
                }
            }
        }
    }
    return minSteps == INT_MAX ? -1 : minSteps;
}

#endif //LEETCODE_CPP_SHORTESTDISTANCESLN_HPP
