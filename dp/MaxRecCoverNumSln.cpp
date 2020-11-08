//
// Created by ZHONGFEI on 2020/11/8.
//

#include "MaxRecCoverNumSln.h"

#include <string>

bool MaxRecCoverNumSln::IsRecNodeCross(struct RecNode &node1, struct RecNode &node2) {
    if (node1.x2 > node2.x1 && node1.x1 < node2.x2 && node1.y2 > node2.y1 && node1.y1 < node2.y2) {
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
    vector<int> coverNums(num + 1, 0);
    for (int i = 1; i < num; i++) {
        for (int j = 0; j < i; j++) {
            if (IsRecNodeCross(nodes[i], nodes[j])) {
                coverNums[i] = max(coverNums[i], coverNums[j] + 1);
            }
        }
    }
}