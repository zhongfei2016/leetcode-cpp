//
// leetcode-cpp
//
//给出 n 生成全部有效括号组合，回溯法 https://leetcode-cn.com/problems/generate-parentheses/

#ifndef LEETCODE_GENERATEBACKTRACESOLUTION_H
#define LEETCODE_GENERATEBACKTRACESOLUTION_H

#include <string>
#include <vector>

using namespace std;

class GenerateBacktraceSolution {
public:
    void backtrace(int left, int right, string& s, vector<string>& res);
    vector<string> generateParenthesis(int n) ;

};


#endif //LEETCODE_GENERATEBACKTRACESOLUTION_H
