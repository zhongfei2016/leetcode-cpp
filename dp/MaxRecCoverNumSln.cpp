//
// Created by ZHONGFEI on 2020/11/8.
//

#include "MaxRecCoverNumSln.h"

#include <string>

RecNode nodeTemp;

bool MaxRecCoverNumSln::IsRecNodeCross(struct RecNode &node1, struct RecNode &node2) {
    int maxX1 = max(node1.x1, node2.x1);
    int maxY1 = max(node1.y1, node2.y1);
    int minX2 = min(node1.x2, node2.x2);
    int minY2 = min(node1.y2, node2.y2);
    if (maxX1 < minX2 && maxY1 < minY2) {
        nodeTemp.x1 = maxX1;
        nodeTemp.y1 = maxY1;
        nodeTemp.x2 = minX2;
        nodeTemp.y2 = minY2;
        return true;
    }
    return false;
}

int MaxRecCoverNumSln::maxRecCoverNum(int num, vector<vector<int> > recs) {
    vector<RecNode> nodes(num);
    for (int i = 0; i < num; i++) {
        nodes[i].x1 = recs[i][0];
        nodes[i].y1 = recs[i][1];
        nodes[i].x2 = recs[i][2];
        nodes[i].y2 = recs[i][3];
    }
    vector<int> coverNums(num, 0);
    int maxVal = 0;
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < i; j++) {
            coverNums[i] = 1;
            if (IsRecNodeCross(nodes[i], nodes[j]) && coverNums[i] < coverNums[j] + 1) {
                coverNums[i] = coverNums[j] + 1;
                maxVal = max(maxVal, coverNums[i]);
            }
        }
    }
    return maxVal;
}