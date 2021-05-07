//
// leetcode-cpp
//

#ifndef LEETCODE_CPP_EXISTPATHSLN_H
#define LEETCODE_CPP_EXISTPATHSLN_H

#include <vector>
#include <string>

using namespace std;

class ExistPathSln {
public:
    bool exist(vector<vector<char>>& board, string word);

    bool dfs(vector<vector<char> > &board, string& endStr, int curIdx, int curX, int curY);
};


#endif //LEETCODE_CPP_EXISTPATHSLN_H
