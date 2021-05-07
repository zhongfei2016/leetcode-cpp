//
// leetcode-cpp
//

#ifndef LEETCODE_CPP_N_NODEMAXDEPTHSLN_H
#define LEETCODE_CPP_N_NODEMAXDEPTHSLN_H

#include <Common.h>

class N_NodeMaxDepthSln {
public:
    int maxDepth(Node* root);
    int maxDepth2(Node* root);

private:
    int dfs(Node* node, int curDepth);
    int dfs2(Node* node);
};


#endif //LEETCODE_CPP_N_NODEMAXDEPTHSLN_H
