//
// leetcode-cpp
//

#ifndef LEETCODE_CPP_MAXRECCOVERNUMSLN_H
#define LEETCODE_CPP_MAXRECCOVERNUMSLN_H

#include <vector>

using namespace std;

struct RecNode {
    // 左下角坐标
    int x1;
    int y1;
    // 右上角坐标
    int x2;
    int y2;
};

class MaxRecCoverNumSln {
public:
    bool IsRecNodeCross(RecNode& node1, RecNode& node2);

    int maxRecCoverNum(int num, vector<vector<int>> recs);
};


#endif //LEETCODE_CPP_MAXRECCOVERNUMSLN_H
