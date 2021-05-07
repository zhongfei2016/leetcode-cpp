//
// leetcode-cpp
//

#include "LongValidBracketSolution.h"
#include <stack>
#include <map>
#include <vector>

int GetMax(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int LongValidBracketSolution::longestValidParentheses(string s) {
    // 暂存坐标的stack
    stack<int> sStack;
    int max = 0;
    sStack.push(-1);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            sStack.push(i);
        } else {
            sStack.pop();
            if (sStack.empty()) {
                sStack.push(i);
            } else {
                max = GetMax(max, (i - sStack.top()));
            }
        }
    }
    return max;
}