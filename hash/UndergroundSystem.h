//
// Created by ZHONGFEI on 2021/2/21.
//

#ifndef LEETCODE_CPP_UNDERGROUNDSYSTEM_H
#define LEETCODE_CPP_UNDERGROUNDSYSTEM_H

#include <string>
#include <unordered_map>

using namespace std;

class UndergroundSystem {
public:
    UndergroundSystem() {

    }

    void checkIn(int id, string stationName, int t) {
        idTimeStatMap[id] = std::make_pair(t, stationName);
    }

    void checkOut(int id, string stationName, int t) {
        auto idIter = idTimeStatMap.find(id);
        string statKey(idIter->second.second + stationName);
        auto iter = statTimeMap.find(statKey);
        if (iter == statTimeMap.end()) {
            statTimeMap[statKey] = std::make_pair(t - idIter->second.first, 1);
            return;
        }
        iter->second = std::make_pair(iter->second.first + t - idIter->second.first, iter->second.second + 1);
    }

    double getAverageTime(string startStation, string endStation) {
        auto iter = statTimeMap.find(startStation + endStation);
        if (iter == statTimeMap.end()) {
            return 0.0;
        }
        return iter->second.first / iter->second.second;
    }

private:
    unordered_map<int, std::pair<int, string>> idTimeStatMap;
    unordered_map<string, std::pair<double, int>> statTimeMap;
};


#endif //LEETCODE_CPP_UNDERGROUNDSYSTEM_H
