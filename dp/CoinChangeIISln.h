//
// leetcode-cpp
//
// 零钱兑换 II https://leetcode-cn.com/problems/coin-change-2/

#ifndef LEETCODE_CPP_COINCHANGEIISLN_H
#define LEETCODE_CPP_COINCHANGEIISLN_H

#include <vector>

using namespace std;

/**
 * https://leetcode-cn.com/problems/coin-change-2/solution/
 */
class CoinChangeIISln {
public:
    int change(int amount, vector<int>& coins);

    int change2(int amount, vector<int>& coins);
};


#endif //LEETCODE_CPP_COINCHANGEIISLN_H
