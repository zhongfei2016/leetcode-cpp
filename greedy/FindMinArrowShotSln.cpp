//
// leetcode-cpp
// 452. 用最少数量的箭引爆气球
// https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons/
//

#include "FindMinArrowShotSln.h"
#include <set>
#include <algorithm>

bool SortPairVec(vector<int> &pair1, vector<int> &pair2) {
    return pair1[1] < pair2[1];// 比较pair的第二个值并按照升序排列（前一个值比后一个值小）
}

// 正解
int FindMinArrowShotSln::findMinArrowShots(vector<vector<int>> &points) {

    if (points.size() == 0) {
        return 0;
    }
    if (points.size() == 1) {
        return 1;
    }
    std::sort(points.begin(), points.end(), SortPairVec);
    int curEnd = points[0][1];
    int result = 1;
    for (auto &point : points) {
        if (point[0] > curEnd) {
            result += 1;
            curEnd = point[1];
        }
    }
    return result;
}

// 算法超时
int FindMinArrowShotSln::findMinArrowShots2(vector<vector<int>> &points) {

    if (points.size() == 0) {
        return 0;
    }
    if (points.size() == 1) {
        return 1;
    }
    std::sort(points.begin(), points.end(), SortPairVec);
    vector<vector<int>> tempPoints = points;
    set<vector<int>> reduentPoints;
    int result = 0;
    for (int i = 0; i < tempPoints.size() - 1; i++) {
        if (reduentPoints.find(tempPoints[i]) != reduentPoints.end()) {
            continue;
        }
        for (int j = i + 1; j < tempPoints.size(); j++) {
            if (tempPoints[i][0] == tempPoints[j][0] && tempPoints[i][1] == tempPoints[j][1]) {
                result += 1;
            }
            if (tempPoints[i][0] <= tempPoints[j][1] && tempPoints[i][1] >= tempPoints[j][0]) {
                reduentPoints.insert(points[j]);
                tempPoints[i][0] = tempPoints[i][0] > tempPoints[j][0] ? tempPoints[i][0] : tempPoints[j][0];
                tempPoints[i][1] = tempPoints[i][1] < tempPoints[j][1] ? tempPoints[i][1] : tempPoints[j][1];
            }
        }
    }
    for (int i = 0; i < points.size(); i++) {
        if (reduentPoints.find(points[i]) == reduentPoints.end()) {
            result++;
        }
    }
    return result;
}