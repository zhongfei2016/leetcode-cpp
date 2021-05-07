//
// leetcode-cpp
// 会议室II https://blog.csdn.net/weixin_39722329/article/details/100641715
/**
 * 给定一个会议时间安排的数组，每个会议时间都会包括开始和结束的时间 [[s1,e1],[s2,e2],...] (si < ei)，为避免会议冲突，同时要考虑充分利用会议室资源，请你计算至少需要多少间会议室，才能满足这些会议安排。
 */

#ifndef LEETCODE_CPP_MEETINGROOMIISLN_H
#define LEETCODE_CPP_MEETINGROOMIISLN_H

#include <vector>

using namespace std;

class MeetingRoomIISln {
public:
    int minMeetingRooms(vector<vector<int>>& intervals);
};


#endif //LEETCODE_CPP_MEETINGROOMIISLN_H
