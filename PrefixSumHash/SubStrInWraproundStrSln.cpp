//
// Created by ZHONGFEI on 2021/4/5.
// https://leetcode-cn.com/problems/unique-substrings-in-wraparound-string/solution/dong-tai-gui-hua-java-by-zyxwmj-dn12/

#include <vector>
#include "SubStrInWraproundStrSln.h"
// 首先需要知道的是，长度为n的字符串s所有子串的个数
// 是以s[0]为结尾的子串个数+以s[1]为结尾的子串个数+...+s[n-1]为结尾的子串个数
// 比如abc，子串为a，b，ab，c，bc，abc
// 而已s[i]为结尾的子串个数即为i+1个，所以所有子串个数为1+2+3+...+(n-1)+n
// 而本题求的是连续子串，只需要加一个是否连续的判断即可
// 正常p[i] - p[i - 1] - 1==0即可判断连续，但也有za这样的字符串，a-z=-25，-25-1=-26，与26取余还是0
int SubStrInWraproundStrSln::findSubstringInWraproundString(string p) {
    int count = 1;
    vector<int> prefixSum(26, 0);
    for (int i = 0; i < p.size(); i++) {
        if (i > 0 && abs(p[i] - p[i - 1] - 1) % 26 == 0) {
            count++;
        } else {
            count = 1;
        }
        prefixSum[p[i] - 'a'] = max(prefixSum[p[i] - 'a'], count);
    }
    int result = 0;
    for (auto prefixItem : prefixSum) {
        result += prefixItem;
    }
    return result;
}
