//
// Created by ZHONGFEI on 2021/3/26.
//
#include "CarPoolingSln.hpp"
#include "CorpFlightBookSln.h"

int main() {
// 拼车 差分 1094
    CarPoolingSln carPoolingSln;
    vector<vector<int>> carPoolTrip = {{3, 2, 7},
                                       {3, 7, 9},
                                       {8, 3, 9}};
    carPoolingSln.carPooling(carPoolTrip, 11);

    CorpFlightBookSln corpFlightBookSln;
    vector<vector<int>> bookings = {{1, 2, 10},
                                    {2, 3, 20},
                                    {2, 5, 25}};
    corpFlightBookSln.corpFlightBookings(bookings, 5);
    return 0;
}