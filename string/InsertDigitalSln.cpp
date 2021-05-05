//
// Created by ZHONGFEI on 2021/5/5.
// 将digit不改变字符顺序不拆散的情况下插入score，获得最大值

#include <cstring>
#include "InsertDigitalSln.h"

std::string InsertDigitalSln::insertDigit(std::string score, std::string digit) {
    int pos = score.length();
    // 找到digit开始大于score的起始点，记为pos
    // 没找到则把digit直接追加到score后面
    for (int i = 0; i < score.length(); i++) {
        string temp = score.substr(i);
        if (digit.compare(temp) > 0) {
            pos = i;
            break;
        }
    }
    // 计算尝试的区间，最长就是digit的长度20，最短就是直接把digit接在score后面，就是1
    int size = 0;
    if (pos == score.length()) {
        size = 1;
    } else {
        // 有可能pos+digit长度长于score长度了，那就试剩下的长度即可
        size = pos + digit.length() > score.length() ? score.length() - pos + 1 : digit.length();
    }
    string ans = "";
    for (int i = 0; i < size; i++) {
        string temp = score.substr(0, pos + i) + digit + score.substr(pos + i);
        ans = temp.compare(ans) > 0 ? temp : ans;
    }
    return ans;
}