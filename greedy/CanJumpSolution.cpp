//
// leetcode-cpp
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

bool CanJumpSolution::canJump1(vector<int> &nums) {
    int n = nums.size();
    // 可以到达的最大的索引数
    int maxRightNum = 0;
    for (int i = 0; i < nums.size(); i++) {
        // 只有每次的最大索引数大于等于当前索引值，才有可能继续往右走
        if (maxRightNum >= i) {
            maxRightNum = max(maxRightNum, i + nums[i]);
            // 如果本次最大索引数大于数组最大索引，则可以到达终点
            if (maxRightNum > n - 1) {
                return true;
            }
        }
    }
    return false;
}

int CanJumpSolution::canJump2(vector<int> &nums) {
    int step = 0;
    int pos = 0;
    int n = nums.size() - 1;// 最后一个值不考虑，要么跳到他，要么跳过他，都符合条件
    while (pos < n) {
        if (step == n) {
            return -1;
        }
        if (pos + nums[pos] >= n) { //第一步可以直接跳到终点
            step++;
            break;
        } else {
            // 计算当前这一步可以跳到的最大值，pos+j是当前位置可以跳的每一个值
            int maxIdx = 0;
            int maxVal = 0;
            for (int j = 1; j <= nums[pos]; j++) {
                if (maxVal < j + nums[pos+j]) {
                    maxVal = j + nums[pos+j];
                    maxIdx = j;
                }
            }
            pos += maxIdx;
            step++;
        }
    }
    return step;
}