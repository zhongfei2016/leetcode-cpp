//
// leetcode-cpp
// 字符串按要求间隔数重排 https://www.cnblogs.com/FdWzy/p/12389956.html
/**
 * 给你一个非空的字符串 s 和一个整数 k，你要将这个字符串中的字母进行重新排列，使得重排后的字符串中相同字母的位置间隔距离至少为 k。

所有输入的字符串都由小写字母组成，如果找不到距离至少为 k 的重排结果，请返回一个空字符串 ""。

示例 1：

输入: s = "aabbcc", k = 3
输出: "abcabc"
解释: 相同的字母在新的字符串中间隔至少 3 个单位距离。
 */

#ifndef LEETCODE_CPP_RERANGESTRSLN_H
#define LEETCODE_CPP_RERANGESTRSLN_H

#include <string>

using namespace std;

class RerangeStrSln {
public:
    string rearrangeString(string s, int k);
};


#endif //LEETCODE_CPP_RERANGESTRSLN_H
