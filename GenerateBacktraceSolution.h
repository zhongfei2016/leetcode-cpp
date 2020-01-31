//
// Created by fei on 2020/1/1.
//

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
