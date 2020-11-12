//
// Created by ZHONGFEI on 2020/3/22.
//
// LRU缓存机制 least recently used https://leetcode-cn.com/problems/lru-cache/

#ifndef LEETCODE_CPP_LRUCACHE_H
#define LEETCODE_CPP_LRUCACHE_H

#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
private:
    int cap;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> map;

public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }

    int get(int key) {
        auto iter = map.find(key);
        // 不存在直接返回-1
        if (iter == map.end()) {
            return -1;
        }
        // 将map中的val拿出来保存
        pair<int, int> kv = *map[key];
        // 存在则先在双向链表中删除
        cache.erase(map[key]);
        // 然后再放到双向链表的最前
        cache.push_front(kv);
        // 然后更新map中val值（list::iterator迭代器位置）
        map[key] = cache.begin();
        return kv.second;
    }

    void put(int key, int value) {
        auto iter = map.find(key);
        // 不存在
        if (iter == map.end()) {
            // 空间已满则在list和map中删除最后一个元素
            if (cache.size() == cap) {
                auto backItem = cache.back();
                int backKey = backItem.first;
                map.erase(backKey);
                cache.pop_back();
            }
            // list刷新，得到新的iterator再更新到map中
            cache.push_front(make_pair(key, value));
            map[key] = cache.begin();
        } else {
            // 已存在，清理其在list中的位置并放到最前，得到新的iterator再更新到map中
            cache.erase(map[key]);
            cache.push_front(make_pair(key, value));
            map[key] = cache.begin();
        }
    }
};


#endif //LEETCODE_CPP_LRUCACHE_H
