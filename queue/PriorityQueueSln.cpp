//
// Created by ZHONGFEI on 2020/10/18.
//

#include "PriorityQueueSln.h"

#include <queue>
#include <iostream>

using namespace std;

struct Item {
    int count;
    int priority;

    Item(int priority, int count) : priority(priority), count(count) {

    }
};

// 优先级由大到小，占用单位从小到大排序
struct cmp {
    bool operator()(Item x, Item y) {
        if (x.priority == y.priority) {
            return x.count > y.count;
        }
        return x.priority < y.priority;
    }
};

void PriorityQueueSln::PriorityQueueTest() {
    priority_queue<Item, vector<Item>, cmp> que;
    que.push(Item(2, 5));
    que.push(Item(1, 1));
    que.push(Item(2, 3));
    que.push(Item(3, 5));
    que.push(Item(2, 4));
    que.push(Item(1, 2));
    que.push(Item(1, 1));
    que.push(Item(4, 1));
    que.push(Item(2, 2));
    while (!que.empty()) {
        std::cout << que.top().priority << "," << que.top().count << std::endl;
        que.pop();
    }
}