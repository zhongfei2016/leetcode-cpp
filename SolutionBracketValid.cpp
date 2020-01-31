//
// Created by fei on 2020/1/1.
//

#include "SolutionBracketValid.h"
#include <map>
#include <stack>

bool SolutionBracketValid::isValid(string s) {
    if (s.empty()) {
        return true;
    }
    if (s.length() <= 1) {
        return false;
    }
    map<char, char> validMap = {{'{', '}'},
                                {'[', ']'},
                                {'(', ')'}};
    stack<char> validStack;
    for (int i = 0; i < s.length(); i++) {
        if (validStack.empty()) {
            // 为空则要看下是不是右括号，即在map中find对应字符
            auto itor = validMap.find(s[i]);
            if (itor == validMap.end()) {
                // 没找到则是右括号，直接报错退出
                return false;
            }
            validStack.push(s[i]);
        } else {
            // 在map中看是否能找到对应字符
            auto itor = validMap.find(s[i]);
            if (itor != validMap.end()) {
                // 找到对应右括号，说明是左括号，有效
                validStack.push(s[i]);
                continue;
            }
            // 如果是右括号，则看与stack最上面的是否匹配，不匹配则退出，匹配则stack弹出最上面一个字符
            if (validMap.at(validStack.top()) != s[i]) {
                return false;
            } else {
                validStack.pop();
            }
        }
    }
    if(!validStack.empty()){
        return false;
    }
    return true;
}
