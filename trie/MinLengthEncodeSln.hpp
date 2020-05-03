//
// Created by ZHONGFEI on 2020/5/2.
//

#ifndef LEETCODE_CPP_MINLENGTHENCODESLN_HPP
#define LEETCODE_CPP_MINLENGTHENCODESLN_HPP
struct TrieNode {
    bool isLeaf = false;
    TrieNode *childNodes[26];
};

class TrieMap {
    TrieNode *root;
public:
    TrieMap() { root = new TrieNode(); };

    int insert(string word) {
        TrieNode *curNode = root;
        bool isNew = false;
        for (int i = word.size() - 1; i >= 0; i--) {
            int ch = word[i] - 'a';
            if (curNode->childNodes[ch] == nullptr) {
                isNew = true;
                curNode->childNodes[ch] = new TrieNode();
            }
            curNode = curNode->childNodes[ch];
        }
        if (isNew) {
            return word.size() + 1;
        }
        return 0;
    }
};

class MinLengthEncodeSln {
public:
    TrieMap trieMap;

    int minimumLengthEncoding(vector<string> &words);
};

static bool compareWord(string &word1, string &word2) {
    return word1.size() > word2.size();
}

int MinLengthEncodeSln::minimumLengthEncoding(vector<std::__cxx11::string> &words) {
    sort(words.begin(), words.end(), compareWord);
    int cnt = 0;
    for (auto word : words) {
        cnt += trieMap.insert(word);
    }
    return cnt;
}

#endif //LEETCODE_CPP_MINLENGTHENCODESLN_HPP
