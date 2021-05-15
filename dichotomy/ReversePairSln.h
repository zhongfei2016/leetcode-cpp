//
// leetcode-cpp
// https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/
//

#ifndef LEETCODE_CPP_REVERSEPAIRSLN_H
#define LEETCODE_CPP_REVERSEPAIRSLN_H

#include <vector>

using namespace std;

class BIT {
private:
    vector<int> tree;
    int n;

public:
    BIT(int _n) : n(_n), tree(_n + 1) {}

    static int lowbit(int x) {
        return x & (-x);
    }

    int query(int x) {
        int ret = 0;
        while (x) {
            ret += tree[x];
            x -= lowbit(x);
        }
        return ret;
    }

    void update(int x) {
        while (x <= n) {
            ++tree[x];
            x += lowbit(x);
        }
    }
};

class ReversePairSln {
public:
    int reversePairs(vector<int> &nums);

    int reversePairs2(vector<int> &nums);

    int reversePairs3(vector<int> &nums);

private:
    int merge(vector<int> &nums, int start, int end);
    int merge3(vector<int> &nums, int start, int end);
    int sort3(vector<int> &nums, int start, int end);
};


#endif //LEETCODE_CPP_REVERSEPAIRSLN_H
