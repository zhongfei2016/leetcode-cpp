//
// leetcode-cpp
// 航班统计 https://leetcode-cn.com/problems/corporate-flight-bookings/
// 差分 https://leetcode-cn.com/problems/corporate-flight-bookings/solution/you-deng-chai-shu-lie-xiang-dao-de-chai-fen-si-xia/

#include "CorpFlightBookSln.h"

// bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
// [1,2,10]表示第一站上车，坐到第二站，所以是第三站下车，第一站下标为0，第三站下标为2
// 每次只统计变化即可，所以只统计上车站0（1-1）和下车站2的人数变化即可answer[i]=answer[i-1]+diff[i]
vector<int> CorpFlightBookSln::corpFlightBookings(vector<vector<int>> &bookings, int n) {
    vector<int> diff(n, 0);
    vector<int> answers(n, 0);
    for (int i = 0; i < bookings.size(); i++) {
        diff[bookings[i][0] - 1] += bookings[i][2];
        // 坐到第n站就是终点站，所以始终不下，就不需要减掉了，只减小于n的
        if (bookings[i][1] < n) {
            diff[bookings[i][1]] -= bookings[i][2];
        }
    }
    answers[0] = diff[0];
    for (int i = 1; i < n; i++) {
        answers[i] = answers[i - 1] + diff[i];
    }
    return answers;
}