//
// Created by ZHONGFEI on 2020/4/25.
//
// 公交路线 https://leetcode-cn.com/problems/bus-routes/

#ifndef LEETCODE_CPP_NUMBUSTODESTSLN_HPP
#define LEETCODE_CPP_NUMBUSTODESTSLN_HPP

#include <map>
#include <set>

using namespace std;

class NumBusToDestSln {
public:
    int numBusesToDestination(vector<vector<int>> &routes, int S, int T);
};

int NumBusToDestSln::numBusesToDestination(vector<vector<int>> &routes, int S, int T) {
    if (S == T) {
        return 0;
    }
    // 统计到每辆车及其所能到达的站点的对应关系，routes的序号就是线路id
    map<int, set<int>> dest2BusesMap;
    int busNum = routes.size();
    for (int bus = 0; bus < busNum; bus++) {
        for (int station = 0; station < routes[bus].size(); station++) {
            dest2BusesMap[routes[bus][station]].insert(bus);
        }
    }
    // 把S所在的每条线路放到队列中，每个线路都是一个可能的起点
    queue<int> que;
    // 因为目的是统计最短换乘次数，所以如果已乘坐过的车就不能重复乘坐了
    // 定义标志数组，标志本轮当前线路是否换乘过
    vector<bool> visited(busNum, false);
    // 首先把起点所在的线路都放到queue中，并置位换乘过标志
    for (auto bus : dest2BusesMap[S]) {
        que.push(bus);
        visited[bus] = true;
    }
    // 换乘次数
    int changeCnt = 0;
    while (!que.empty()) {
        int size = que.size();
        changeCnt++;
        // 遍历本轮所有可能性
        for (int k = 0; k < size; k++) {
            int curBus = que.front();
            que.pop();
            // 遍历当前bus所有站点是否有目的站点，有直接返回换成次数
            for (int station : routes[curBus]) {
                if (station == T) {
                    return changeCnt;
                }
                // 否则将每个站点所对应的bus都加入队列，为了不重复乘坐，加入队列的置为已访问
                for (int bus : dest2BusesMap[station]) {
                    if (visited[bus] == false) {
                        que.push(bus);
                        visited[bus] = true;
                    }
                }
            }
        }
    }
    return -1;
}

#endif //LEETCODE_CPP_NUMBUSTODESTSLN_HPP
