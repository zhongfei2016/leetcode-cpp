//
// leetcode-cpp
//

#include "DailyTempSln.h"

#include <stack>

vector<int> DailyTempSln::dailyTemperatures(vector<int> &T) {
    stack<int> idxStack;
    vector<int> res(T.size(), 0);
    for (int i = 0; i < T.size(); i++) {
        if (idxStack.empty()) {
            idxStack.push(i);
            continue;
        }
        while (!idxStack.empty() && T[i] > T[idxStack.top()]) {
            res[idxStack.top()] = i - idxStack.top();
            idxStack.pop();
        }
        idxStack.push(i);
    }
    return res;
}