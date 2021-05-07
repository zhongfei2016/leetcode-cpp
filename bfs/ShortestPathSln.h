//
// leetcode-cpp
//

#ifndef LEETCODE_CPP_SHORTESTPATHSLN_H
#define LEETCODE_CPP_SHORTESTPATHSLN_H

#include <vector>

using namespace std;

class ShortestPathSln {
public:
    static vector<vector<int>> dirs;
    int shortestPath(vector<vector<int>> grid, int k);
};


#endif //LEETCODE_CPP_SHORTESTPATHSLN_H
