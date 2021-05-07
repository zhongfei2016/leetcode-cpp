//
// leetcode-cpp
//

#include <algorithm>
#include "ReversePairSln.h"

// 归并排序顺便计算一下逆序对
int ReversePairSln::merge(vector<int> &nums, int start, int end) {
    // 起始索引相同，为规避排序回升点，此时没有逆序对，直接返回
    if (start == end) {
        return 0;
    }
    // 计算中间索引，为了避免大数导致的移除，改用减法计算
    int mid = start + (end - start) / 2;
    // 递归调用，计算左右两组的逆序对个数
    int count = merge(nums, start, mid) + merge(nums, mid + 1, end);
    // 分左右指针合并当前组，前提是当前组左右两分组都是有序的，并计算当前组的逆序对数
    int left = start;
    int right = mid + 1;
    int idx = 0;
    // 暂存排序后的数组
    vector<int> temp(end - start + 1, 0);
    while (left <= mid && right <= end) {
        // 如果当前左大于右值，又因为左右分组各有序，所以，左分组从当前左值开始的所有左值，都大于当前右值，所以计数加上mid + 1 - left
        count += nums[left] > nums[right] ? mid + 1 - left : 0;
        temp[idx++] = nums[left] <= nums[right] ? nums[left++] : nums[right++];
    }
    while (left <= mid) {
        // 此时右边没数了，即便左边数再大也不会有新的逆序对了
        temp[idx++] = nums[left++];
    }
    while (right <= end) {
        // 此时左边没数了，右边有数也是更大的数了，也构不成逆序对
        temp[idx++] = nums[right++];
    }
    // 排序后要保证原数组nums里此部分有序，所以要拷进去
    std::copy(temp.begin(), temp.end(), nums.begin() + start);
    return count;
}

int ReversePairSln::reversePairs(vector<int> &nums) {
    if (nums.size() < 2) {
        return 0;
    }
    return merge(nums, 0, nums.size() - 1);
}

int ReversePairSln::reversePairs2(vector<int> &nums) {
    int n = nums.size();
    vector<int> tmp = nums;
    // 离散化
    sort(tmp.begin(), tmp.end());
    for (int &num: nums) {
        auto iter = lower_bound(tmp.begin(), tmp.end(), num);
        auto idx = iter - tmp.begin();
        num = idx + 1;
    }
    // 树状数组统计逆序对
    BIT bit(n);
    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        ans += bit.query(nums[i] - 1);
        bit.update(nums[i]);
    }
    return ans;
}
