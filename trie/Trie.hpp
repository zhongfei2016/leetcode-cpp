//
// leetcode-cpp
//

#ifndef LEETCODE_CPP_TRIE_HPP
#define LEETCODE_CPP_TRIE_HPP

class Trie {
private:
    bool isLeaf;
    Trie *next[26];

public:
    /** Initialize your data structure here. */
    Trie() {
        isLeaf = false;
        for (int i = 0; i < 26; i++) {
            next[i] = nullptr;
        }
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *cur = this;
        for (char ch : word) {
            int idx = ch - 'a';
            if (cur->next[idx] == nullptr) {
                cur->next[idx] = new Trie();
            }
            cur = cur->next[idx];
        }
        cur->isLeaf = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *cur = this;
        for (char ch : word) {
            if (cur->next[ch - 'a'] == nullptr) {
                return false;
            }
            cur = cur->next[ch - 'a'];
        }
        return cur->isLeaf;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *cur = this;
        for (char ch : prefix) {
            if (cur->next[ch - 'a'] == nullptr) {
                return false;
            }
            cur = cur->next[ch - 'a'];
        }
        return true;
    }
};

#endif //LEETCODE_CPP_TRIE_HPP
