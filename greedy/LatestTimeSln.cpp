//
// Created by ZHONGFEI on 2021/5/2.
//

#include <map>
#include "LatestTimeSln.h"

int LatestTimeSln::latestTime(vector<int> distribute, int num, vector<int> arrive) {
    std::map<int, int> arriveCnt;
    std::map<int, int> distributeCnt;
    for (auto &arr : arrive) {
        arriveCnt[arr]++;
    }
    for (auto &dis : distribute) {
        distributeCnt[dis] = num;
    }
    int distributeIdx = 0;
    for (auto iterDis = distributeCnt.begin(); iterDis != distributeCnt.end();) {
        auto iterArrive = arriveCnt.begin();
        for (; iterArrive != arriveCnt.end();) {
            if (distributeIdx == distributeCnt.size() - 1) {
                // 最后一个放票时间，此时到达的人到达时间晚于最后一个放票时间
                // 而且此放票时间还有票，取当前放票时间即可
                if (iterArrive->first > iterDis->first) {
                    return iterDis->first;
                }
                // 最后一个放票时间，此时到达的人到达时间早于或等于最后一个放票时间
                while (iterArrive != arriveCnt.end() && iterArrive->first <= iterDis->first) {
                    // 当前时间的人数大于放票数，则取放票时间的前一个时间点
                    if (iterArrive->second >= iterDis->second) {
                        return iterDis->first - 1;
                    } else {
                        // 否则用此放票时间对应的人数减掉当前时间点到达人数并将iterArrive++
                        iterDis->second -= iterArrive->second;
                        iterArrive++;
                    }
                }
                // 如果iterArrive为end说明后面没人了，还有票，则取放票时间即可
                // 如果iterArrive.first>iterDis.first, 则说明后面到的人拿不到票了，也取当前放票时间即可
                return iterDis->first;
            }
            if (iterArrive->first <= iterDis->first) {
                if (iterArrive->second > iterDis->second) {
                    iterArrive->second -= iterDis->second;
                    iterDis++;
                    distributeIdx++;
                } else if (iterArrive->second == iterDis->second) {
                    iterArrive++;
                    iterDis++;
                    distributeIdx++;
                } else {
                    iterDis->second -= iterArrive->second;
                    iterArrive++;
                }
            } else {
                iterDis++;
                distributeIdx++;
            }
        }
        if (iterArrive == arriveCnt.end()) {
            break;
        }
    }
    // 所有人已遍历完，还有票，则以最后一个放票时间点返回
    return distributeCnt.rend()->first;
}