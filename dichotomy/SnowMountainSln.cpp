//
// Created by ZHONGFEI on 2020/11/1.
//

#include "SnowMountainSln.h"

#include <algorithm>
#include <math.h>

int Mean(vector<int> &mountainHeights) {
    int ans = 0;
    for (int hei : mountainHeights) {
        ans += hei;
    }
    return ans / mountainHeights.size();
}

/**
 * 输入：altitude = [5,1,4,3,8], difference = 3
  输出：8
  解释：将 1 变成 3，8 变成 6 ，这时最高是 6，最小是 3，相差不超过 3。需要成本为：2^2 + 2^2 = 8
 */


int SnowMountainSln::snowMountainCost(vector<int> mountainHeights, int diff) {
    int avg = Mean(mountainHeights);
    int leftAvg = avg;
    int rightAvg = leftAvg + diff;
    int minRes = INT_MAX;
    int count = 1;
    bool isReturn = false;

    while (leftAvg > 0 && rightAvg < INT_MAX) {
        long long temp = 0;
        for (int hei: mountainHeights) {
            if (hei - rightAvg > 0) {
                long long tempR = hei - rightAvg;
                temp += tempR * tempR;
            }
            if (leftAvg - hei > 0) {
                long long tempL =leftAvg- hei;
                temp += tempL * tempL;
            }
        }
        temp = temp % 1000000007;
        if (temp > minRes) {
            if (isReturn) {
                break;
            }
            isReturn = true;
            leftAvg = avg;
            rightAvg = leftAvg + diff;
            count = -1;
        }
        minRes = min(minRes, (int)temp);
        leftAvg += count;
        rightAvg += count;
    }
    return minRes;
}