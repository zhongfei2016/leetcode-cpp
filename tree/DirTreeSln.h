//
// Created by ZHONGFEI on 2021/3/31.
//

#ifndef LEETCODE_CPP_DIRTREESLN_H
#define LEETCODE_CPP_DIRTREESLN_H

#include <vector>
#include <string>
#include "Common.h"

using namespace std;

class DirTreeSln {
public:
    StrNode *BuildNodeTree(vector<string> &dirs);
    int getIdx(string dir);
    string getDirName(string dir);
};


#endif //LEETCODE_CPP_DIRTREESLN_H
