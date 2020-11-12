// 旋转数组 https://leetcode-cn.com/problems/rotate-array/

#include <algorithm>

using namespace std;

class RotateSln {
public:
    void rotate(vector<int> &nums, int k);
};

void RotateSln::rotate(vector<int> &nums, int k) {
    if (nums.empty()) {
        return;
    }
    k = k % nums.size();
    // 先整个翻转
    reverse(nums.begin(), nums.end());
    // 翻转后再翻转前k个数，即0——k-1，因为C++里给定的end端迭代器不参与翻转，所以此时nums[k]不翻转
    reverse(nums.begin(), nums.begin() + k);
    // 赞翻转K+1到n的数，即k——n-1
    reverse(nums.begin() + k, nums.end());
}