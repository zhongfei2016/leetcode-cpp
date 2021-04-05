//
// Created by ZHONGFEI on 2021/4/4.
// 森林中的兔子 https://leetcode-cn.com/problems/rabbits-in-forest/

#include <unordered_map>
#include "NumRabbitSln.h"

int NumRabbitSln::numRabbits(vector<int> &answers) {
    std::unordered_map<int, int> color2NumMap;
    int result = 0;
    for (auto answer : answers) {
        // 如果当前没有报这个数的，result里加上报的这个数字以及报这个数的兔子
        // 并存人hash表（只存报的数字即可，当前兔子已被减去，后续再有报相同数字的再减1）
        if (color2NumMap[answer] == 0) {
            result += answer + 1;
            color2NumMap[answer]=answer;
        } else {
            // 如果又有一只报这个数的，则减1
            // 直到清零后，还有报这个数字的，说明是另一种颜色的兔子了，重新按上面的逻辑计数
            color2NumMap[answer]--;
        }
    }
    return result;
}
