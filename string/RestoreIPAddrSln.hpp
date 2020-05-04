//
// Created by ZHONGFEI on 2020/5/4.
//

#ifndef LEETCODE_CPP_RESTOREIPADDRSLN_HPP
#define LEETCODE_CPP_RESTOREIPADDRSLN_HPP

#include <regex>
#include <queue>
// 复原IP地址，dfs深度遍历 https://leetcode-cn.com/problems/restore-ip-addresses/
class RestoreIPAddrSln {
public:
    void dfs(string curStr, int n, string curIp, vector<string> &res);

    vector<string> restoreIpAddresses(string s);
};

void RestoreIPAddrSln::dfs(string curStr, int n, string curIp, vector<string> &res) {
    if (n == 4) {
        // 处理了4段，如果剩余字符串为空，则符合要求，如果字符串仍有剩余则不符合要求直接return
        if (curStr.empty()) {
            res.push_back(curIp);
        }
        return;
    }
    // 尝试长度为1-3的数字
    for (int len = 1; len < 4; len++) {
        if (curStr.size() < len) {
            break;
        }
        // 将截取的字符串转为数字
        int val = stoi(curStr.substr(0, len));
        // 数字大于255或者转回去的长度不符合要求，比如01,05这种，转成数字再转成字符串就变成1和5了
        if (val > 255 || to_string(val).size() != len) {
            continue;
        }
        dfs(curStr.substr(len), n + 1, curIp + curStr.substr(0, len) + (n == 3 ? "" : "."), res);
    }
    return;
}

vector<string> RestoreIPAddrSln::restoreIpAddresses(string s) {
    vector<string> resVec;
    if (s.size() < 4 || s.size() > 12) {
        return resVec;
    }
    string res;
    dfs(s, 0, res, resVec);
    return resVec;
}

#endif //LEETCODE_CPP_RESTOREIPADDRSLN_HPP
