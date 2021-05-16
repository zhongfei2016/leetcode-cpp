//
// leetcode
//

#ifndef LEETCODE_CPP_MAXCOINSSLN_H
#define LEETCODE_CPP_MAXCOINSSLN_H

#include <vector>

using namespace std;

class MaxCoinsSln {
public:
    int maxCoins1(vector<int> &nums);

    int maxCoins2(vector<int> &nums);

    int maxCoins3(vector<int> &nums);

private:
    void dfs1(vector<int> &nums, int curCoins, int *ans);

    int dfs2(vector<int> &nums, vector<vector<int>> &dp, int i, int j);
};


#endif //LEETCODE_CPP_MAXCOINSSLN_H
