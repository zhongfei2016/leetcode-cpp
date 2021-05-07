//
// leetcode-cpp
//

#include "SearchSolution.h"

int SearchSolution::search(vector<int> &nums, int target)
{
    int start = 0;
    int end = nums.size()-1;
    while (start <= end) {
        int mid = (start + end) / 2;//mid算左边的值的索引
        if(nums[mid] == target){//target是mid对应的值
            return mid;
        }

        // 左右两边总有一个有序，在有序的这里判断target是否在这边，是就将范围缩小到左边，否则将范围缩小到右边
        if(nums[start]<=nums[mid]){//当前左边有序
            if(target >= nums[start] && target < nums[mid]){//target肯定不是mid对应的值，target在左边范围内
                end = mid -1;// 右边被丢弃，end的坐标值缩小为原来的一半
            }
            else {
                start = mid +1;//// 左边被丢弃，start的坐标值增大到mid+1
            }
        }
        else {//当前右边有序
            if(target >nums[mid] && target<=nums[end])//target肯定不是mid对应的值，在右边范围内
            {
                start = mid +1;
            }else{
                end = mid -1;
            }
        }
    }
    return -1;
}