//
// Created by ZHONGFEI on 2020/10/21.
// https://leetcode-cn.com/problems/queue-reconstruction-by-height/
//

#include "ReconstructQueueSln.h"

#include <algorithm>

vector<vector<int> > ReconstructQueueSln::reconstructQueue(vector<vector<int> > &people) {
    std::sort(people.begin(), people.end(),
              [](const vector<int> &p1, const vector<int> &p2) {
                  if (p1[0] == p2[0]) { return p1[1] < p2[1]; }
                  return p1[0] > p2[0];
              });

    vector<vector<int>> temp;
    for (auto iter = people.begin(); iter != people.end(); iter++) {
        temp.insert(temp.begin() + (*iter)[1], *iter);
    }
    return temp;
}