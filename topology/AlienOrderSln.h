//
// leetcode-cpp
// 拓扑排序，火星词典 https://michael.blog.csdn.net/article/details/107346218
//

/**
现有一种使用字母的全新语言，这门语言的字母顺序与英语顺序不同。

假设，您并不知道其中字母之间的先后顺序。
但是，会收到词典中获得一个 不为空的 单词列表。
因为是从词典中获得的，所以该单词列表内的单词已经 按这门新语言的字母顺序进行了排序。

您需要根据这个输入的列表，还原出此语言中已知的字母顺序。
示例 1：
输入:
[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]
输出: "wertf"

示例 2：
输入:
[
  "z",
  "x"
]
输出: "zx"
 */
#ifndef LEETCODE_CPP_ALIENORDERSLN_H
#define LEETCODE_CPP_ALIENORDERSLN_H

#include <vector>
#include <string>

using namespace std;

class AlienOrderSln {
public:
    string alienOrder(vector<string>& words);
};


#endif //LEETCODE_CPP_ALIENORDERSLN_H
