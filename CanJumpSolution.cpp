//
// Created by ZHONGFEI on 2020/1/30.
//

#include "CanJumpSolution.h"

//[2,0,1,0,1]
bool CanJumpSolution::canJump(vector<int> &nums) {
    // 记当前遇到的0的idx
    int zeroIdx = -1;
    // 是否可跳过标志，遇到0则置为false，然后判断前一个元素的值是否可以跳过刚才碰到的0，能跳过才置为true，然后继续往前找0
    bool jumpFLag = true;
    // 从后往前遍历数组
    for (int i = nums.size() - 2; i >= 0; i--) {
        // 当前元素非0且后面都没有0，就继续往前找
        if (nums[i] != 0 && zeroIdx < 0) {
            continue;
        }
        //当前元素为0且后面未遇到跳不过的0，就记下当前0的idx，然后跳过标志置为false，表示当前的0跳不过去之前再遇到0也不关注
        if (nums[i] == 0 && jumpFLag) {
            zeroIdx = i;
            jumpFLag = false;
            continue;
        }
        // 判断是不是非0，且有未跳过的0，此时判断是否nums[i] > (zeroIdx - i)，是的话说明当前的0可以跳过，如果i==0就返回true
        // 不然就清理zeroIdx继续往前遍历查找下一个0，直到数组首位
        if (nums[i] != 0 && zeroIdx >= 0) {
            if (nums[i] > (zeroIdx - i)) {
                jumpFLag = true;
                if (i == 0) {
                    return true;
                }
                zeroIdx = -1;
                continue;
            } else {
                if (i == 0) {
                    return false;
                }
                continue;
            }
        }
    }
    if (zeroIdx == 0) {
        return false;
    }
    return true;
}