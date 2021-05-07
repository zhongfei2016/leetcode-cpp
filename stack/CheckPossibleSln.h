//
// leetcode-cpp
//

#ifndef LEETCODE_CPP_CHECKPOSSIBLESLN_H
#define LEETCODE_CPP_CHECKPOSSIBLESLN_H

#include <vector>

using namespace std;

class CheckPossibleSln {
public:
    bool checkPossibility(vector<int>& nums);
    bool forwardCheck(vector<int> &nums);
    bool backwardCheck(vector<int> &nums);
};


#endif //LEETCODE_CPP_CHECKPOSSIBLESLN_H
