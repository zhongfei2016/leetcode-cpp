//
// leetcode-cpp
// 区间问题汇总 https://mp.weixin.qq.com/s/ioUlNa4ZToCrun3qb4y4Ow

#include "MergeIntervalSolution.h"
#include <algorithm>

vector<vector<int>> MergeIntervalSolution::merge(vector<vector<int>> &intervals) {
    if (intervals.empty()) {
        return intervals;
    }
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> out;
    vector<int> temp;
    temp.insert(temp.end(), intervals[0].begin(), intervals[0].end());
    for (int i = 0; i < intervals.size() - 1; i++) {
        if (intervals[i].back() >= intervals[i + 1].front() && intervals[i].front() <= intervals[i + 1].back()) {
            if (intervals[i].back() < intervals[i + 1].back()) {
                temp.pop_back();
                temp.push_back(intervals[i + 1].back());
            }
            if (intervals[i].front() > intervals[i + 1].front()) {
                int tempBack = temp.back();
                temp.clear();
                temp.push_back(intervals[i + 1].front());
                temp.push_back(tempBack);
            }
            intervals[i + 1].clear();
            intervals[i + 1].insert(intervals[i + 1].end(), temp.begin(), temp.end());
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

// 将区间数组中有交集的区间融合并输出
vector<vector<int>> MergeIntervalSolution::merge2(vector<vector<int>> &intervals) {
    std::sort(intervals.begin(), intervals.end());
    // 定义结果集和起始索引，索引-1表示结果集为空，为0表示结果集有一个值，以此类推
    vector<vector<int>> result;
    int curIdx = -1;
    for (int i = 0; i < intervals.size(); i++) {
        // 如果是为空则直接将第一个值塞入结果集
        // 如果后一个区间（i代表后一个区间的索引）起始值大于结果集当前区间的结束值
        // 则无交集，也可以直接塞入结果集
        if (curIdx == -1 || intervals[i][0] > result[curIdx][1]) {
            curIdx++;
            result.push_back(intervals[i]);
        } else {
            // 否则，取结果集当前区间和后一个区间的结束值的最大值作为
            // 此时当前区间的结束值当前区间和后一区间融合
            auto curMaxEnd = max(result[curIdx][1], intervals[i][1]);
            result[curIdx][1] = curMaxEnd;
        }
    }
    return result;
}

// 插入的新区间需要与原区间数组中与之有交集的区间融合唯一，输出插入后的区间数组（原区间数组有序）
vector<vector<int> > MergeIntervalSolution::insert(vector<vector<int> > &intervals, vector<int> &newInterval) {
    int curIdx = 0;
    vector<vector<int>> results;
    // 先将前面无交集的直接塞入结果集（当前区间后值比新区间前值小）
    while (curIdx < intervals.size() && intervals[curIdx][1] < newInterval[0]) {
        results.push_back(intervals[curIdx]);
        curIdx++;
    }
    // 如果后续区间前值小于等于新区间后值，则一定有交集，开始融合后续区间和新区间
    vector<int> temp(newInterval.begin(), newInterval.end());
    while (curIdx < intervals.size() && intervals[curIdx][0] <= temp[1]) {
        auto minVal = min(temp[0], intervals[curIdx][0]);
        auto maxVal = max(temp[1], intervals[curIdx][1]);
        temp.clear();
        temp.push_back(minVal);
        temp.push_back(maxVal);
        curIdx++;
    }
    // 后续区间前值大于新区间后值，再无交集，直接塞入结果集
    results.push_back(temp);
    while (curIdx < intervals.size()) {
        results.push_back(intervals[curIdx]);
        curIdx++;
    }
    return results;
}

int MergeIntervalSolution::removeCoveredIntervals(vector<vector<int> > &intervals) {
    // 按起始值排序后，后面区间的起始值一定大于前一区间的起始值
    std::sort(intervals.begin(), intervals.end(), [](vector<int> &lhs, vector<int> &rhs) { return lhs[0] < rhs[0]; });
    vector<vector<int>> results;
    for (int i = 0; i < intervals.size(); i++) {
        // （后包住前）后一个区间结束值大于结果集最后一个区间结束值，开始值小于等于最后一个区间的开始值，合并
        // —————
        // ————————
        // （前包住后）后一区间结束值小于等于结果集最后一个区间结束值，开始值大于等于最后一个区间的开始值，合并
        // —————————
        //   —————
        if (!results.empty() && ((intervals[i][0] <= results.back().at(0) && intervals[i][1] >= results.back().at(1)) ||
                                 (intervals[i][0] >= results.back().at(0) &&
                                  intervals[i][1] <= results.back().at(1)))) {
            // 取最大值作为结束值合并
            results.back().at(1) = max(intervals[i][1], results.back().at(1));
        } else {
            results.push_back(intervals[i]);
        }
    }
    return results.size();
}