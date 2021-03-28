//
// Created by ZHONGFEI on 2021/3/26.
//
#include "queue/PriorityQueueSln.h"
#include "queue/RerangeStrSln.h"
#include "queue/TaskScheduleSln.h"
#include "queue/ReorganizeStrSln.h"
#include "queue/CarPoolSln.h"
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> carPoolTrip = {{3, 2, 7},
                                       {3, 7, 9},
                                       {8, 3, 9}};
    CarPoolSln carPoolSln;
    carPoolSln.carPooling(carPoolTrip, 11);

    // 优先级队列
    PriorityQueueSln priorityQueueSln;
    priorityQueueSln.PriorityQueueTest();

    RerangeStrSln rerangeStrSln;
    rerangeStrSln.rearrangeString("aabbcc", 3);

    TaskScheduleSln taskScheduleSln;
    taskScheduleSln.leastInterval({'A', 'A', 'A', 'B', 'B', 'B'}, 2);

    ReorganizeStrSln reorganizeStrSln;
    reorganizeStrSln.reorganizeString("aab");
    return 0;
}