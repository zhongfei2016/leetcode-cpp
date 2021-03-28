//
// Created by ZHONGFEI on 2021/3/26.
//
#include "CarPoolingSln.hpp"

int main() {
// 拼车 差分 1094
    CarPoolingSln carPoolingSln;
    vector<vector<int>> carPoolTrip = {{3, 2, 7},
                                       {3, 7, 9},
                                       {8, 3, 9}};
    carPoolingSln.carPooling(carPoolTrip, 11);
    return 0;
}