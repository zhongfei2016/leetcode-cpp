//
// Created by ZHONGFEI on 2021/4/4.
// 缺页中断 OPT置换算法 https://blog.csdn.net/u011080472/article/details/51206332

#ifndef LEETCODE_CPP_OPTSLN_H
#define LEETCODE_CPP_OPTSLN_H

#include <vector>
#include <string>

using namespace std;

class OPTSln {
public:
    /**
     *
     * @param cacheCnt 缓存容量
     * @param visitPages 访问的页面页码
     * @return
     */
    int GetPageBrokeCnt(int cacheCnt, vector<int> visitPages);
};


#endif //LEETCODE_CPP_OPTSLN_H
