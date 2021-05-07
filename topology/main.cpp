//
// leetcode-cpp
//

#include "AlienOrderSln.h"
#include "CanFinCourseSln.hpp"
#include "SeqReconstructSln.hpp"
#include "FindCourseOrderSln.hpp"

int main()
{
    AlienOrderSln alienOrderSln;
    vector<string> alienWords = {"wrt", "wrf", "er", "ett", "rftt"};
    alienOrderSln.alienOrder(alienWords);

    // 拓扑排序 课程表I https://leetcode-cn.com/problems/course-schedule/
    CanFinCourseSln canFinCourseSln;
    vector<vector<int>> canFinCourseVec = {{1, 0},
                                           {2, 0},
                                           {3, 1},
                                           {3, 2}};
    canFinCourseSln.canFinish(4, canFinCourseVec);

    // 拓扑排序 课程表II https://leetcode-cn.com/problems/course-schedule-ii/
    FindCourseOrderSln findCourseOrderSln;
    vector<vector<int>> findCourseVec = {{1, 0},
                                         {2, 0},
                                         {3, 1},
                                         {3, 2}};
    findCourseOrderSln.findOrder(4, findCourseVec);

    SeqReconstructSln seqReconstructSln;
    vector<int> seqReconstructOrg = {4, 1, 5, 2, 6, 3};
    vector<vector<int>> seqReconstructSeqs = {{5, 2, 6, 3},
                                              {4, 1, 5, 2}};
    seqReconstructSln.sequenceReconstruction(seqReconstructOrg, seqReconstructSeqs);
    return 0;
}