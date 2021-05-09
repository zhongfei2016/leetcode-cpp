//
// leetcode-cpp
//
// 合并区间 https://leetcode-cn.com/problems/merge-intervals/

#ifndef LEETCODE_MERGEINTERVALSOLUTION_H
#define LEETCODE_MERGEINTERVALSOLUTION_H

#include <vector>
#include <string>

using namespace std;

class MergeIntervalSolution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals);

    // 区间类题目：
    // 1、合并区间
    vector<vector<int>> merge2(vector<vector<int>> &intervals);
    // 2、插入区间
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int>& newInterval);
    // 3、删除被覆盖区间
    int removeCoveredIntervals(vector<vector<int>>& intervals);
    // 4、汇总区间
    vector<string> summaryRanges(vector<int>& nums);
    // 5、俄罗斯套娃信封问题
    int maxEnvelopes(vector<vector<int>>& envelopes);
};


#endif //LEETCODE_MERGEINTERVALSOLUTION_H
