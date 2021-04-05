//
// Created by ZHONGFEI on 2021/3/26.
//
#include "LongestConsecutiveSln.h"
#include "UndergroundSystem.h"
#include "FrequencySortSln.h"
#include "NumRabbitSln.h"

int main() {
    // 最长连续序列 https://leetcode-cn.com/problems/longest-consecutive-sequence/
    LongestConsecutiveSln longestConsecutiveSln;
    vector<int> longestConsecutiveVec = {100, 4, 200, 1, 3, 2};
    longestConsecutiveSln.longestConsecutive(longestConsecutiveVec);

    UndergroundSystem undergroundSystem;
    undergroundSystem.checkIn(45, "Leyton", 3);
    undergroundSystem.checkIn(32, "Paradise", 8);
    undergroundSystem.checkIn(27, "Leyton", 10);
    undergroundSystem.checkOut(45, "Waterloo", 15);
    undergroundSystem.checkOut(27, "Waterloo", 20);
    undergroundSystem.checkOut(32, "Cambridge", 22);
    undergroundSystem.getAverageTime("Paradise",
                                     "Cambridge");       // 返回 14.0。从 "Paradise"（时刻 8）到 "Cambridge"(时刻 22)的行程只有一趟
    undergroundSystem.getAverageTime("Leyton",
                                     "Waterloo");          // 返回 11.0。总共有 2 躺从 "Leyton" 到 "Waterloo" 的行程，编号为 id=45 的乘客出发于 time=3 到达于 time=15，编号为 id=27 的乘客于 time=10 出发于 time=20 到达。所以平均时间为 ( (15-3) + (20-10) ) / 2 = 11.0
    undergroundSystem.checkIn(10, "Leyton", 24);
    undergroundSystem.getAverageTime("Leyton", "Waterloo");          // 返回 11.0
    undergroundSystem.checkOut(10, "Waterloo", 38);
    undergroundSystem.getAverageTime("Leyton", "Waterloo");          // 返回 12.0

    FrequencySortSln frequencySortSln;
    frequencySortSln.frequencySort2("tree");

    NumRabbitSln numRabbitSln;
    vector<int> rabbitAns = {1, 1, 2};
    numRabbitSln.numRabbits(rabbitAns);
    return 0;
}