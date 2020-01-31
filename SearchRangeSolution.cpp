//
// Created by ZHONGFEI on 2020/1/5.
//

#include "SearchRangeSolution.h"
vector<int> SearchRangeSolution::searchRange(vector<int>& nums, int target) {
    //stack存下标
    vector<int> results(2,-1);
    for(int i=0;i<nums.size();i++){
        if(nums[i] == target){
            if(results[0] == -1){
                results[0] = i;
            }
            results[1] = i;
        }
    }
    return results;
}