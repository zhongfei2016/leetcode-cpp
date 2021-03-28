//
// Created by ZHONGFEI on 2021/3/26.
//
#include "LRUCache.h"

int main() {
    // LRU缓存机制 least recently used https://leetcode-cn.com/problems/lru-cache/
    LRUCache cache(2 /* 缓存容量 */ );
    cache.put(1, 1);
    cache.put(2, 2);
    cache.get(1);
    cache.put(3, 3);
    cache.get(2);
    cache.put(4, 4);
    cache.get(1);
    cache.get(3);
    cache.get(4);
    return 0;
}