//
// leetcode-cpp
//

#include "LetterCombiSolution.h"
#include <map>
#include <queue>


vector<string> LetterCombiSolution::letterCombinations(string digits) {
    map<char, vector<string>> letterMap;
    letterMap['2'] = {"a", "b", "c"};
    letterMap['3'] = {"d", "e", "f"};
    letterMap['4'] = {"g", "h", "i"};
    letterMap['5'] = {"j", "k", "l"};
    letterMap['6'] = {"m", "n", "o"};
    letterMap['7'] = {"p", "q", "r", "s"};
    letterMap['8'] = {"t", "u", "v"};
    letterMap['9'] = {"w", "x", "y", "z"};

    queue<string> strQueue;
    vector<string> results;
    for (int i = 0; i < digits.length(); i++) {
        if (strQueue.empty()) {
            // 队列为空时将第一个数字对应的字母塞到queue中
            for (int j = 0; j < letterMap.at(digits[i]).size(); j++) {
                strQueue.push(letterMap.at(digits[i])[j]);
            }
        } else {
            // 遍历queue中每一个string，追加上当前的数字对应的每一个字母塞到queue中，再把queue原有的string都pop出去
            int size = strQueue.size();
            while (size != 0) {
                for (int j = 0; j < letterMap.at(digits[i]).size(); j++) {
                    string temp = strQueue.front();
                    temp += letterMap.at(digits[i])[j];
                    strQueue.push(temp);
                }
                strQueue.pop();
                size --;
            }
        }
    }
    while (!strQueue.empty()){
        results.push_back(strQueue.front());
        strQueue.pop();
    }
    return results;
}