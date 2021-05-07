//
// leetcode-cpp
//

#include "MeetingRoomIISln.h"

#include <algorithm>
#include <queue>

struct RoomTimeCmp {
    bool operator()(const vector<int> &lhs, const vector<int> &rhs) {
        return lhs[1] > rhs[1];
    }
};

int MeetingRoomIISln::minMeetingRooms(vector<vector<int>> &intervals) {
    std::sort(intervals.begin(), intervals.end(),
              [](const vector<int> &lhs, const vector<int> &rhs) { return lhs[0] < rhs[0]; });
    priority_queue<vector<int>, vector<vector<int>>, RoomTimeCmp> que;
    for (int i = 0; i < intervals.size(); i++) {
        while (!que.empty() && que.top()[1] <= intervals[i][0]) {
            que.pop();
        }
        que.push(intervals[i]);
    }
    return que.size();
}