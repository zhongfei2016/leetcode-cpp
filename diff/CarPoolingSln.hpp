//
// Created by ZHONGFEI on 2020/5/2.
//
// 拼车 差分 1094 https://leetcode-cn.com/problems/car-pooling/

#ifndef LEETCODE_CPP_CARPOOLINGSLN_HPP
#define LEETCODE_CPP_CARPOOLINGSLN_HPP

#include <vector>
using namespace std;
class CarPoolingSln {
public:
    bool carPooling(vector<vector<int>> &trips, int capacity);
};

bool CarPoolingSln::carPooling(vector<vector<int> > &trips, int capacity) {
    //定义差值数组，计算每个值上车人数和下车人数的计算值，上车加人，下车减人
    vector<int> diff(1001, 0);
    for (int i = 0; i < trips.size(); i++) {
        int start = trips[i][1];
        diff[start] += trips[i][0];
        int end = trips[i][2];
        diff[end] -= trips[i][0];
    }
    // 当期车辆的人数，通过累加各个站点的差分值，都不能大于最大容量才可以
    // 相当于一辆车顺序经过各个站点，有的站上人，有的站下人，有的站没人
    int curCapacity = 0;
    for (int i = 0; i < 1001; i++) {
        curCapacity += diff[i];
        if (curCapacity > capacity) {
            return false;
        }
    }
    return true;
}

#endif //LEETCODE_CPP_CARPOOLINGSLN_HPP
