//
// Created by ZHONGFEI on 2020/11/15.
//

#include "CarPoolSln.h"

#include <algorithm>
#include <queue>

struct Passenger {
    int nums;
    int start;
    int end;

    Passenger(int nums, int start, int end) : nums(nums), start(start), end(end) {}

    bool operator<(const Passenger &rhs) const {
        return this->start < rhs.start;
    }
};

struct cmpStart {
    bool operator()(const Passenger &lhs, const Passenger &rhs) {
        return lhs.start < rhs.start;
    }
};

struct cmp {
    bool operator()(const Passenger &lhs, const Passenger &rhs) {
        return lhs.end > rhs.end;
    }
};

bool CarPoolSln::carPooling(vector<vector<int>> &trips, int capacity) {
    vector<Passenger> sortTrips;
    for (int i = 0; i < trips.size(); i++) {
        sortTrips.push_back(Passenger(trips[i][0], trips[i][1], trips[i][2]));
    }
    std::sort(sortTrips.begin(), sortTrips.end(), cmpStart());

    priority_queue<Passenger, vector<Passenger>, cmp> que;
    for (int i = 0; i < sortTrips.size(); i++) {
        while (!que.empty() && que.top().end <= sortTrips[i].start) {
            // 有nums人下车，容量增加
            capacity += que.top().nums;
            que.pop();
        }
        // 队列是以end排序，所以每次push进去，end小的在前面
        que.push(sortTrips[i]);
        capacity -= sortTrips[i].nums;
        if (capacity < 0) {
            return false;
        }
    }
    return true;
}