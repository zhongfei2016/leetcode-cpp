//
// Created by ZHONGFEI on 2021/5/5.
// 小李在A/B两城市工作，往返AB有多趟列车，arrangement是发车、到站的时刻的数组，arrangement的一维下标是列车编号
// 任意两趟列车要么完全不重叠要么一个完全包在另一个里面
// 给定一个时刻数组，找出里面每个时刻最快的列车编号，没有返回-1

#include <map>
#include "ManageTimeSln.h"

namespace {
    struct Train {
        int trainId;
        int time;

        Train() = default;

        Train(int trainId, int time) {
            this->trainId = trainId;
            this->time = time;
        }
    };
}

vector<int> ManageTimeSln::manageTime(vector<vector<int> > arrangement, vector<int> timePoints) {
    // 目标是找出每一个时刻的最快的列车编号，预期的结构是<时刻,最快列车id>，然后直接找即可
    std::map<int, Train> trainMap;
    for (int i = 0; i < arrangement.size(); i++) {
        int curTime = arrangement[i][1] - arrangement[i][0];
        // 左闭右开，所以要小于右值
        for (int j = arrangement[i][0]; j < arrangement[i][1]; j++) {
            auto trainIter = trainMap.find(j);
            if (trainIter != trainMap.end() && trainIter->second.time > curTime) {
                trainIter->second = Train(i, curTime);
            }
            if (trainIter == trainMap.end()) {
                trainMap[j] = Train(i, curTime);
            }
        }
    }
    vector<int> ans(timePoints.size(), -1);
    for (int i = 0; i < timePoints.size(); i++) {
        auto trainIter = trainMap.find(timePoints[i]);
        if (trainIter != trainMap.end()) {
            ans[i] = trainIter->second.trainId;
        }
    }
    return ans;
}