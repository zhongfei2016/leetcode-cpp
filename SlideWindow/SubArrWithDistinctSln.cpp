//
// Created by ZHONGFEI on 2021/4/5.
// 题解 ：https://leetcode-cn.com/problems/subarrays-with-k-different-integers/solution/cong-zui-jian-dan-de-wen-ti-yi-bu-bu-tuo-7f4v/

#include <map>
#include "SubArrWithDistinctSln.h"

int SubArrWithDistinctSln::subArrayAtMost(vector<int> &A, int maxNum) {
    std::map<int, int> typeNumMap;
    int left = 0;
    int right = 0;
    int result = 0;
    while (right < A.size()) {// 限制右指针
        typeNumMap[A[right]]++;// 往map中加值，map是当前数字在当前left-right区间的个数
        while (typeNumMap.size() > maxNum) {// 数字种类大于预期，则开始移动左指针
            typeNumMap[A[left]]--;// 先减去左边界值
            if (typeNumMap[A[left]] == 0) {
                typeNumMap.erase(A[left]);// 看对应种类是否已清零，清零的直接剔除
            }
            left++;// 减去左边界后并处理完map后左边界才可以右移
        }
        result += right - left + 1;// 计算种类最多为maxNum的子数组个数，所以个数小于maxNum的也算
        right++;
    }
    return result;
}

int SubArrWithDistinctSln::subarraysWithKDistinct(vector<int> &A, int K) {
    int result = subArrayAtMost(A, K) - subArrayAtMost(A, K - 1);
    return result;
}
