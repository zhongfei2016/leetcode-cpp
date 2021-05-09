//
// leetcode-cpp
// 岛屿的周长 https://leetcode-cn.com/problems/island-perimeter/
// 这个思路不错 https://leetcode-cn.com/problems/island-perimeter/solution/shou-hua-tu-jie-463-dao-yu-de-zhou-chang-by-xiao_b/

#ifndef LEETCODE_CPP_LANDPEREMITERSLN_H
#define LEETCODE_CPP_LANDPEREMITERSLN_H

#include <vector>

using namespace std;

class LandPeremiterSln {
public:
    int islandPerimeter(vector<vector<int>> &grid);

private:
    int dfs(vector<vector<int>>& grid, int i, int j);
};


#endif //LEETCODE_CPP_LANDPEREMITERSLN_H
