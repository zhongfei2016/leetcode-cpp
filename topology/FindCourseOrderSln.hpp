//
// leetcode-cpp
//
// 拓扑排序 课程表II https://leetcode-cn.com/problems/course-schedule-ii/

#ifndef LEETCODE_CPP_FINDCOURSEORDERSLN_HPP
#define LEETCODE_CPP_FINDCOURSEORDERSLN_HPP
// 拓扑排序 课程表II https://leetcode-cn.com/problems/course-schedule-ii/
class FindCourseOrderSln {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites);
};

/**
 *
 * @param numCourses 课程数，课程序号从0到numCourses-1
 * @param prerequisites 课程依赖顺序，第二维只有两个数，为两个课程序号，前者需要依赖后者
 * 所以上课顺序必须是prerequisite[1]-->prerequisite[0]
 * @return
 */
vector<int> FindCourseOrderSln::findOrder(int numCourses, vector<vector<int> > &prerequisites) {
    if (numCourses <= 0) {
        return vector<int>(0);
    }
    vector<int> res(0, 0);
    // 定义入度数组，即每个课程有没有依赖的前置课程
    vector<int> inDegrees(numCourses, 0);
    // 定义邻接表，即某个课程紧接着都可能有哪些课程
    vector<unordered_set<int>> graph(numCourses, unordered_set<int>(0));
    for (auto prerequisite : prerequisites) {
        graph[prerequisite[1]].insert(prerequisite[0]);
        inDegrees[prerequisite[0]]++;
    }
    // queue中只放入度是0的课程
    queue<int> courseQue;
    for (int i = 0; i < numCourses; i++) {
        if (inDegrees[i] == 0) {
            courseQue.push(i);
        }
    }
    while (!courseQue.empty()) {
        // 取出当前课程，当前课程入度一定为0，满足要求，放入res中
        int course = courseQue.front();
        res.push_back(course);
        courseQue.pop();
        // 取出当前课程的邻接课程
        unordered_set<int> nextCourses = graph[course];
        // 遍历其所有邻接课程将每一个入度减1
        for (auto nextCourse : nextCourses) {
            inDegrees[nextCourse]--;
            // 入度为0则放入queue
            if (inDegrees[nextCourse] == 0) {
                courseQue.push(nextCourse);
            }
        }
    }
    // 所有课程都放入res了则返回，否则没有结果返回空数组
    if (res.size() == numCourses) {
        return res;
    }
    return vector<int>(0);
}

#endif //LEETCODE_CPP_FINDCOURSEORDERSLN_HPP
