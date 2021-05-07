//
// leetcode-cpp
//
// 计算右侧小于当前元素的个数 https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/

#include <vector>
#include <iostream>

using namespace std;

class SolutionCountSmaller {
public:
    vector<int> countSmaller(vector<int> &nums);
    vector<int> countSmaller2(vector<int> &nums);

private:
    void merge(vector<pair<int, int>> &vec, vector<int>& count);
    void merge(vector<pair<int, int>> &vec, int start, int end, vector<int>& count);
    void mergeTwo(vector<pair<int, int>> &vec1, vector<pair<int, int>> &vec2, vector<pair<int, int>> &vec, vector<int>& count);
};