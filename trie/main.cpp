//
// Created by ZHONGFEI on 2021/3/26.
//
#include "MinLengthEncodeSln.hpp"
#include "ReplaceWordsSln.hpp"
#include "Trie.hpp"
#include <vector>
#include <string>
using namespace std;
int main() {
    // 单词的压缩编码 820 拓扑排序
    MinLengthEncodeSln minLengthEncodeSln;
    vector<string> minLenEncodeVec = {"time", "me", "bell"};
    minLengthEncodeSln.minimumLengthEncoding(minLenEncodeVec);

    // 单词替换 拓扑排序 https://leetcode-cn.com/problems/replace-words/
    ReplaceWordsSln replaceWordsSln;
    vector<string> replaceWordVec = {"cat", "bat", "rat"};
    replaceWordsSln.replaceWords(replaceWordVec, "the cattle was rattled by the battery");
    return 0;
}