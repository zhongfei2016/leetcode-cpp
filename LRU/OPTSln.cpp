//
// leetcode-cpp
//

#include <unordered_map>
#include <unordered_set>
#include "OPTSln.h"

int OPTSln::GetPageBrokeCnt(int cacheCnt, vector<int> visitPages) {
    std::unordered_map<int, int> pageMap;
    int curCacheIdx = 0;// 已载入缓存页面个数
    int brokeCnt = 0;// 页面中断次数
    for (int i = 0; i < visitPages.size(); i++) {
        int curItem = visitPages[i];
        auto pageIter = pageMap.find(curItem);
        if (pageIter != pageMap.end()) {
            continue;
        }
        if (curCacheIdx < cacheCnt) {
            pageMap[curItem] = curCacheIdx;
            curCacheIdx++;
            brokeCnt++;
            continue;
        } else {
            // 将map中当前页码放入set中，遍历后续还未放入map的待访问页码
            // 遇到set中有的就从set中剔除，直到set中只剩下最后一个，这个就是当前可预见的最后才访问的页码
            // 把这个最后才访问的页码从map中剔除，并将待访问的页码放入map中，更新为刚才从map剔除的页码对应的idx
            std::unordered_set<int> tempPages;
            for (auto &mapIter: pageMap) {
                tempPages.insert(mapIter.first);
            }
            for (int j = i; j < visitPages.size(); j++) {
                tempPages.erase(visitPages[j]);
                if (tempPages.size() == 1) {
                    auto delItem = *tempPages.begin();
                    int itemIdx = pageMap[delItem];
                    pageMap.erase(delItem);
                    pageMap[curItem] = itemIdx;
                    brokeCnt++;
                    break;
                }
            }
            // 如果后续待访问页已遍历完但set中还有多个页码
            // 则随机选第一个作为要剔除的页码，并将其idx给待访问的页码，作为新的key-value放入map
            if (pageMap.find(curItem) == pageMap.end()) {
                auto delItem = *tempPages.begin();
                int itemIdx = pageMap[delItem];
                pageMap.erase(delItem);
                pageMap[curItem] = itemIdx;
                brokeCnt++;
                break;
            }
        }
    }
    return brokeCnt;
}
