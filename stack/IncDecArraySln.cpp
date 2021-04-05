//
// Created by ZHONGFEI on 2020/4/6.
//

#include "IncDecArraySln.h"

#include <stack>
#include <algorithm>
#include <climits>

int IncDecArraySln::GetIncDecNum(vector<int> nums) {
    vector<int> incTempVec;
    vector<int> decTempVec;
    vector<int> incVec;
    vector<int> decVec;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums.size(); j++) {
            if (j != i) {
                if (incTempVec.empty()) {
                    incTempVec.push_back(nums[j]);
                } else if (incTempVec.back() <= nums[j]) {
                    incTempVec.push_back(nums[j]);
                }
                if (decTempVec.empty()) {
                    decTempVec.push_back(nums[j]);
                } else if (decTempVec.back() >= nums[j]) {
                    decTempVec.push_back(nums[j]);
                }
            }
        }
        if (incTempVec.size() == nums.size() - 1) {
            incVec.push_back(nums[i]);
        }
        incTempVec.clear();
        if (decTempVec.size() == nums.size() - 1) {
            decVec.push_back(nums[i]);
        }
        decTempVec.clear();
    }
    int min = INT_MAX;
    if (incVec.size()>0) {
        std::sort(incVec.begin(), incVec.end());
        min = incVec[0] < min? incVec[0] : min;
    }
    if (decVec.size()>0) {
        std::sort(decVec.begin(), decVec.end());
        min = decVec[0] < min? decVec[0] : min;
    }
    if (min == INT_MAX) {
        return -1;
    }
    return min;
}