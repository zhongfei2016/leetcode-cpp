//
// leetcode-cpp
// 水果成篮 https://leetcode-cn.com/problems/fruit-into-baskets/

#include <map>
#include "TotalFruitSln.h"

int TotalFruitSln::totalFruit(vector<int> &tree) {
    // 用于存果树类型——个数的键值对
    std::map<int, int> fruitTypes;
    int left = 0;
    int right = 0;
    int maxCount = 0;
    while (left < tree.size() && right < tree.size()) {
        fruitTypes[tree[right]]++;
        while (fruitTypes.size() > 2) {
            // 最多有两个篮子，每个篮子只能放一个类型
            // 个数超过两个就开始减左指针指向的类型，减到0就从map中剔除
            fruitTypes[tree[left]]--;
            maxCount = max(maxCount, right - left);
            if (fruitTypes[tree[left]] == 0) {
                fruitTypes.erase(tree[left]);
            }
            left++;
        }
        right++;
    }
    maxCount = max(maxCount, right - left);
    return maxCount;
}
