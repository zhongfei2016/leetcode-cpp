//
// leetcode-cpp
//
// 单词替换 拓扑排序 https://leetcode-cn.com/problems/replace-words/

#ifndef LEETCODE_CPP_REPLACEWORDSSLN_HPP
#define LEETCODE_CPP_REPLACEWORDSSLN_HPP

struct TrieReplaceNode {
    bool isLeaf = false;
    string word;
    TrieReplaceNode *childNodes[26];
};

class ReplaceWordsSln {
public:
    string replaceWords(vector<string> &dict, string sentence);
};

vector<string> splitStr(string str, string separate) {
    vector<string> strWords;
    int separateLen = separate.length();
    int startPos = 0;
    int idx = -1;
    while ((idx = str.find(separate, startPos)) != -1) {
        strWords.push_back(str.substr(startPos, idx - startPos));
        startPos = idx + separateLen;
    }
    string lastStr = str.substr(startPos);
    if (!lastStr.empty()) {
        strWords.push_back(lastStr);
    }
    return strWords;
}

string ReplaceWordsSln::replaceWords(vector<string> &dict, string sentence) {
    TrieReplaceNode *trie = new TrieReplaceNode();
    vector<string> sentenceWords = splitStr(sentence, " ");
    for (string word : dict) {
        TrieReplaceNode *cur = trie;
        for (char ch : word) {
            if (cur->childNodes[ch - 'a'] == nullptr) {
                cur->childNodes[ch - 'a'] = new TrieReplaceNode();
            }
            cur = cur->childNodes[ch - 'a'];
        }
        cur->isLeaf = true;
        cur->word = word;
    }
    string res;
    for (string sentenceWord : sentenceWords) {
        if (!res.empty()) {
            res.append(" ");
        }
        TrieReplaceNode *cur = trie;
        for (char ch : sentenceWord) {
            // 没找到这个单词的这个字母（字典里没这个单词）或者这是最后一个字母的叶子结点，其word字段有值
            if (cur->childNodes[ch - 'a'] == nullptr || !cur->word.empty()) {
                break;
            }
            cur = cur->childNodes[ch - 'a'];
        }
        res.append(!cur->word.empty() ? cur->word : sentenceWord);
    }
    return res;
}

#endif //LEETCODE_CPP_REPLACEWORDSSLN_HPP
