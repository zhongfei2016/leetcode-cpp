//
// leetcode-cpp
//

#include "SingleNumberSln.h"

int SingleNumberSln::singleNumber(vector<int> &nums) {
    int res = 0;
    // 异或的妙用
    for (int num :nums) {
        res ^= num;
    }
    return res;
}