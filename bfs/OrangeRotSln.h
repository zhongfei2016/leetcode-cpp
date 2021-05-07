//
// leetcode-cpp
//
// 腐烂的橘子 https://leetcode-cn.com/problems/rotting-oranges/

#ifndef LEETCODE_CPP_ORANGEROTSLN_H
#define LEETCODE_CPP_ORANGEROTSLN_H

#include <vector>

using namespace std;

class OrangeRotSln {
public:
    int orangesRotting(vector<vector<int>>& grid);
    int orangesRotting2(vector<vector<int>>& grid);

private:
    static vector<vector<int>> dirs;
};


#endif //LEETCODE_CPP_ORANGEROTSLN_H
