//
// Created by ZHONGFEI on 2020/5/2.
//

#ifndef LEETCODE_CPP_CHECKSUBARRAYSUMSLN_HPP
#define LEETCODE_CPP_CHECKSUBARRAYSUMSLN_HPP

class CheckSubArraySumSln {
public:
    bool checkSubarraySum(vector<int> &nums, int k);
    bool checkSubarraySum2(vector<int> &nums, int k);
};

// 连续的子数组和 https://leetcode-cn.com/problems/continuous-subarray-sum/
bool CheckSubArraySumSln::checkSubarraySum(vector<int> &nums, int k) {
    int sum = 0, count = 0;
    // 题目要求是k的整数倍，虽然数组都是非负整数，但是整数倍可能是-1倍或-2倍，很操蛋
    if (k < 0) {
        k = -k;
    }
    for (int i = 0; i < nums.size(); i++) {
        sum = 0;
        count = 0;
        for (int j = i; j < nums.size(); j++) {
            sum += nums[j];
            count++;
            if (k != 0) {
                if (sum % k == 0 && count >= 2) {
                    return true;
                }
            } else {
                if (sum == 0 && count >= 2) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool CheckSubArraySumSln::checkSubarraySum2(vector<int> &nums, int k) {
    int n = nums.size();
    if (n == 0) { return false; }

    if (k == 0) {
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] == nums[i] && nums[i] == 0) {
                return true;
            }
        }
        return false;
    } else {
        vector<int> preSum(n + 1);
        unordered_map<int, vector<int>> intMap;
        preSum[0] = 0;
        for (int i = 1; i <= n; i++) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
            intMap[preSum[i] % k].push_back(i);
        }
        intMap[preSum[0] % k].push_back(0);

        for (int i = 1; i <= n; i++) {
            int index = preSum[i] % k;
            for (auto iter : intMap[index]) {
                if (i - iter > 1) { return true; }
            }
        }
        return false;
    }
}

#endif //LEETCODE_CPP_CHECKSUBARRAYSUMSLN_HPP
