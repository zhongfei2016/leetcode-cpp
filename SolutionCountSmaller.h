//
// Created by fei on 2019/12/21.
//
#include <vector>
#include <iostream>

using namespace std;

class SolutionCountSmaller {
public:
    vector<int> countSmaller(vector<int> &nums);

private:
    void merge(vector<pair<int, int>> &vec, vector<int>& count);
    void mergeTwo(vector<pair<int, int>> &vec1, vector<pair<int, int>> &vec2, vector<pair<int, int>> &vec, vector<int>& count);
};