//
// leetcode-cpp
//

#ifndef LEETCODE_CPP_DIRTREESLN_H
#define LEETCODE_CPP_DIRTREESLN_H

#include <vector>
#include <string>
#include <unordered_set>
#include "Common.h"

using namespace std;

class DirTreeSln {
public:
    StrNode *BuildNodeTree(vector<string> &dirs);
    int getIdx(string dir);
    string getDirName(string dir);
    bool dfsDeleteDirs(StrNode *parent, const unordered_set<string> &delDirs, vector<string>&result);
};


#endif //LEETCODE_CPP_DIRTREESLN_H
