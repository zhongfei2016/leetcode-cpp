//
// Created by ZHONGFEI on 2020/10/21.
// https://leetcode-cn.com/problems/queue-reconstruction-by-height/
// 每个 people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，前面 正好 有 ki 个身高大于或等于 hi 的人。

#include "ReconstructQueueSln.h"

#include <algorithm>

vector<vector<int> > ReconstructQueueSln::reconstructQueue(vector<vector<int> > &people) {
    // 身高按降序排，前面有几个人按升序排
    std::sort(people.begin(), people.end(),
              [](const vector<int> &p1, const vector<int> &p2) {
                  if (p1[0] == p2[0]) { return p1[1] < p2[1]; }
                  return p1[0] > p2[0];
              });

    // 然后按照前面有几个人依次插入队列
    vector<vector<int>> temp;
    for (auto iter = people.begin(); iter != people.end(); iter++) {
        temp.insert(temp.begin() + (*iter)[1], *iter);
    }
    return temp;
}