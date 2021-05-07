//
// leetcode-cpp
//
// 贪心算法 分享巧克力 https://www.cnblogs.com/slowbirdoflsh/p/11738134.html

#ifndef LEETCODE_CPP_DIVIDECHOCOLATESLN_HPP
#define LEETCODE_CPP_DIVIDECHOCOLATESLN_HPP

#include <algorithm>

// 贪心算法 分享巧克力 https://www.cnblogs.com/slowbirdoflsh/p/11738134.html
class DivideChocolateSln {
public:
    int maximizeSweetness(vector<int> sweetness, int K);

    int maximizeSweetness2(vector<int> sweetness, int K);
};

int DivideChocolateSln::maximizeSweetness(vector<int> sweetness, int K) {
    std::sort(sweetness.begin(), sweetness.end());
    int totalSweet = 0;
    // 先统计所有甜度值
    for (auto sweet : sweetness) {
        totalSweet += sweet;
    }
    // 求平均值，平均值是希望的分给K个朋友和自己时
    // 自己即便拿最小的一份也是所有可能的情况里自己能拿到的最大值
    int avg = totalSweet / (K + 1);
    // 当均值大于0就开始遍历尝试
    while (avg > 0) {
        // 统计份数，从0开始，切一次算一份
        // 因为最后一份也要算，也要符合要求才行，所以符合要求后也会加1
        int curK = 0;
        // 统计每份的和，比如第一份是前三块，甜度为1,2,3，和为6
        int curSum = 0;
        for (auto sweet : sweetness) {
            curSum += sweet;
            // 当前的和大于等于均值，符合分给朋友的要求，份数加1
            if (curSum >= avg) {
                // 当前的份数+1
                curK++;
                // 要分给K+1个人，所以份数大于等于K+1即可
                if (curK >= K + 1) {
                    return avg;
                }
                curSum = 0;
            }
        }
        // 遍历到最后份数也不够，则减小每份甜度和的值
        avg--;
    }
    return avg;
}

int DivideChocolateSln::maximizeSweetness2(vector<int> sweetness, int K) {
    std::sort(sweetness.begin(), sweetness.end());
    int totalSweet = 0;
    // 先统计所有甜度值
    for (auto sweet : sweetness) {
        totalSweet += sweet;
    }
    // 求平均值，平均值是希望的分给K个朋友和自己时
    // 自己即便拿最小的一份也是所有可能的情况里自己能拿到的最大值
    // 但这里使用二分法，0为初始左值，最大可能的均值作为初始右值
    int left = 0, right = totalSweet / (K + 1);
    int selfChocolate = 0;
    // 当左值小于右值时就遍历尝试
    while (left < right) {
        // 先求左右值的中间值，即从中间根据实际情况向两边移动
        // 每次移动一半的一半，这样跨度比一个一个值移动要快
        int mid = (left + right) >> 1;
        // 统计份数，从0开始，切一次算一份
        // 因为最后一份也要算，也要符合要求才行，所以符合要求后也会加1
        int curK = 0;
        // 统计每份的和，比如第一份是前三块，甜度为1,2,3，和为6
        int curSum = 0;
        for (auto sweet : sweetness) {
            curSum += sweet;
            // 当前的和大于等于本次的均值，符合分给朋友的要求，份数加1
            if (curSum >= mid) {
                // 当前的份数+1
                curK++;
                // 要分给K+1个人
                if (curK >= K + 1) {
                    break;
                }
                curSum = 0;
            }
        }
        // 如果份数够了，但自己得到的不一定是最大的
        // 所以先保存一下当前的最大值，然后左值从均值+1开始，再来一次
        if (curK >= K + 1) {
            left = mid + 1;
            selfChocolate = max(mid, selfChocolate);
        } else {
            right = mid - 1;
        }
    }
    return selfChocolate;
}

#endif //LEETCODE_CPP_DIVIDECHOCOLATESLN_HPP
