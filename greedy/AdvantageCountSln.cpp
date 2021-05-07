//
// leetcode-cpp
// https://leetcode-cn.com/problems/advantage-shuffle/ 田忌赛马  优势洗牌
//

#include <algorithm>
#include <functional>
#include "AdvantageCountSln.h"

vector<int> AdvantageCountSln::advantageCount(vector<int> &A, vector<int> &B) {
    std::sort(A.begin(), A.end(), greater<int>());
    // B的顺序固定，所以其索引要记下来，要以B的顺序排序A的顺序争取最大结果
    vector<pair<int, int>> pairB;
    for (int i = 0; i < B.size(); i++) {
        pairB.push_back({B[i], i});
    }
    std::sort(pairB.begin(), pairB.end(), [](pair<int, int> &l, pair<int, int> &r) { return l.first > r.first; });
    int idx = 0;
    int idxB = 0;
    int endIdx = A.size() - 1;
    std::vector<int> result(A.size(), 0);
    // 比较的原则是当前A最大值比B最大值大，则记下A当前最大值，否则记下A当前最小值
    // 然后移动索引继续往下比
    while (idx <= endIdx) {
        if (A[idx] > pairB[idxB].first) {
            result[pairB[idxB].second] = A[idx];
            idx++;
        } else {
            result[pairB[idxB].second] = A[endIdx];
            endIdx--;
        }
        idxB++;

    }
    return result;
}