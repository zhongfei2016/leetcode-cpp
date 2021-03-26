//
// Created by ZHONGFEI on 2020/5/2.
//
// 拓扑排序 课程表I https://leetcode-cn.com/problems/course-schedule/

#ifndef LEETCODE_CPP_CANFINCOURSESLN_HPP
#define LEETCODE_CPP_CANFINCOURSESLN_HPP

#include <unordered_set>
#include <queue>
// 课程表I 拓扑排序 https://leetcode-cn.com/problems/course-schedule/
class CanFinCourseSln {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites);
};

bool CanFinCourseSln::canFinish(int numCourses, vector<vector<int> > &prerequisites) {
// 定义入度数组
    if (numCourses <= 0) {
        return true;
    }
    vector<int> inDegrees(numCourses, 0);
    // 定义邻接表
    vector<unordered_set<int>> graph(numCourses, unordered_set<int>(0));
    for (auto prerequisite : prerequisites) {
        graph[prerequisite[1]].insert(prerequisite[0]);
        inDegrees[prerequisite[0]]++;
    }
    queue<int> courseQue;
    for (int i = 0; i < inDegrees.size(); i++) {
        if (inDegrees[i] == 0) {
            courseQue.push(i);
        }
    }
    vector<int> res;
    while (!courseQue.empty()) {
        int curCourse = courseQue.front();
        courseQue.pop();
        res.push_back(curCourse);
        for (auto nextCourse:graph[curCourse]) {
            inDegrees[nextCourse]--;
            if (inDegrees[nextCourse] == 0) {
                courseQue.push(nextCourse);
            }
        }
    }
    if (res.size() == numCourses) {
        return true;
    }
    return false;
}

#endif //LEETCODE_CPP_CANFINCOURSESLN_HPP
