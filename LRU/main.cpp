//
// leetcode-cpp
//
#include <vector>
#include "LRUCache.h"
#include "OPTSln.h"

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

    vector<int> optVec = {2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2};
    OPTSln optSln;
    optSln.GetPageBrokeCnt(3, optVec);
    return 0;
}