//
// Created by ZHONGFEI on 2020/10/17.
//

#include "SuffixOperationSln.h"

#include <vector>
#include <stack>
#include <map>
#include <regex>
#include <cmath>

// https://www.cnblogs.com/niujifei/p/11603003.html
vector<string> ToSuffixStack(vector<string> &operation) {
    regex reg("\\d+");
    map<string, int> operaPrevilege = {{"+", 1},
                                       {"-", 1},
                                       {"*", 2},
                                       {"/", 2}};
    stack<string> operatorStack;
    vector<string> resultStack;
    for (auto item : operation) {
        if (regex_match(item, reg)) {
            resultStack.push_back(item);
        } else if (item == "(") {
            operatorStack.push(item);
        } else if (item == ")") {
            while (operatorStack.top() != "(") {
                resultStack.push_back(operatorStack.top());
                operatorStack.pop();
            }
            operatorStack.pop();
        } else {
            while (!operatorStack.empty() && operaPrevilege[item] <= operaPrevilege[operatorStack.top()]) {
                resultStack.push_back(operatorStack.top());
                operatorStack.pop();
            }
            operatorStack.push(item);
        }
    }
    while (!operatorStack.empty()) {
        resultStack.push_back(operatorStack.top());
        operatorStack.pop();
    }
    return resultStack;
}

vector<string> Str2Vec(string &str) {
    vector<string> result;
    int i = 0;
    while (i < str.size()) {
        if (str[i] >= '0' && str[i] <= '9') {
            string temp;
            while (i < str.size() && str[i] >= '0' && str[i] <= '9') {
                temp.push_back(str[i]);
                i++;
            }
            result.push_back(temp);
        } else {
            result.push_back(string(&str[i], 1));
            i++;
        }
    }
    return result;
}

bool IsDouble(string &str) {
    char *p = nullptr;
    double val = std::strtod(str.c_str(), &p);
    return p != str.c_str() && *p == '\0' && val != HUGE_VAL;
}

double CalSuffixStack(vector<string> suffixStack) {
    stack<double> numStack;
    for (auto item : suffixStack) {
        if (IsDouble(item)) {
            char *p = nullptr;
            numStack.push(std::strtod(item.c_str(), &p));
        } else {
            auto num1 = numStack.top();
            numStack.pop();
            auto num2 = numStack.top();
            numStack.pop();
            double num = 0;
            switch (item[0]) {
                case '+':
                    num = num1 + num2;
                    numStack.push(num);
                    break;
                case '-':
                    num = num2 - num1;
                    numStack.push(num);
                    break;
                case '*':
                    num = num1 * num2;
                    numStack.push(num);
                    break;
                case '/':
                    num = num2 / num1;
                    numStack.push(num);
                    break;
            }
        }
    }
    return numStack.top();
}

double SuffixOperationSln::CalOperation(string str) {
    vector<string> strList = Str2Vec(str);
    vector<string> suffixList = ToSuffixStack(strList);
    return CalSuffixStack(suffixList);
}