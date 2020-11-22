//
// Created by ZHONGFEI on 2020/1/30.
//

#include "MergeIntervalSolution.h"
#include <algorithm>

vector<vector<int>> MergeIntervalSolution::merge(vector<vector<int>> &intervals) {
    if (intervals.empty()) {
        return intervals;
    }
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> out;
    vector<int> temp;
    temp.insert(temp.end(), intervals[0].begin(), intervals[0].end());
    for (int i = 0; i < intervals.size() - 1; i++) {
        if (intervals[i].back() >= intervals[i + 1].front() && intervals[i].front() <= intervals[i+1].back()) {
            if (intervals[i].back() < intervals[i + 1].back()) {
                temp.pop_back();
                temp.push_back(intervals[i + 1].back());
            }
            if (intervals[i].front() > intervals[i + 1].front()){
                int tempBack = temp.back();
                temp.clear();
                temp.push_back(intervals[i + 1].front());
                temp.push_back(tempBack);
            }
            intervals[i + 1].clear();
            intervals[i + 1].insert(intervals[i + 1].end(),temp.begin(),temp.end());
        } else {
            out.push_back(temp);
            temp.clear();
            temp.insert(temp.end(), intervals[i + 1].begin(), intervals[i + 1].end());
        }
    }
    if (!temp.empty()) {
        out.push_back(temp);
    }
    return out;
}