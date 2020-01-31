//
// Created by fei on 2020/1/1.
//

#include "GenerateBacktraceSolution.h"

// 深度优先遍历
void GenerateBacktraceSolution::backtrace(int left, int right, string& s, vector<string>& res) {
    if(left == 0 && right == 0){
        res.push_back(s);
        return;
    }

    if(left > 0)
    {
        s += "(";
        backtrace(left-1, right, s, res);
        s.pop_back();
    }

    if(right > left){
        s += ")";
        backtrace(left, right-1, s, res);
        s.pop_back();
    }
}
vector<string> GenerateBacktraceSolution::generateParenthesis(int n) {
    vector<string> res;
    string s;
    backtrace(n, n, s, res);
    return res;
}