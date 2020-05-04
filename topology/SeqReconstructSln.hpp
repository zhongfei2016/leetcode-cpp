//
// Created by ZHONGFEI on 2020/5/4.
//

#ifndef LEETCODE_CPP_SEQRECONSTRUCTSLN_HPP
#define LEETCODE_CPP_SEQRECONSTRUCTSLN_HPP

// 拓扑排序 序列重建 LeetCode 444 https://blog.csdn.net/weixin_30319097/article/details/95986939
class SeqReconstructSln {
public:
    bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs);
};

bool SeqReconstructSln::sequenceReconstruction(vector<int> &org, vector<vector<int> > &seqs) {
    vector<int> itemPair;
    vector<vector<int>> itemPairVec;
    queue<int> itemQue;
    unordered_map<int, int> inDegrees;
    unordered_map<int, unordered_set<int>> inDegreeSets;
    for (vector<int> &seq : seqs) {
        for (int i = 0; i < seq.size() - 1; i++) {
            inDegrees[seq[i]] = 0;
            itemPair.push_back(seq[i]);
            itemPair.push_back(seq[i + 1]);
            itemPairVec.push_back(itemPair);
            itemPair.clear();
        }
    }
    unordered_map<int, unordered_set<int>> graph;
    for (auto item : itemPairVec) {
        if (inDegreeSets[item[1]].find(item[0]) == inDegreeSets[item[1]].end()) {
            inDegrees[item[1]]++;
            inDegreeSets[item[1]].insert(item[0]);
        }
        graph[item[0]].insert(item[1]);
    }
    for (auto inDegree : inDegrees) {
        if (inDegree.second == 0) {
            itemQue.push(inDegree.first);
        }
    }
    vector<int> res;
    while (!itemQue.empty()) {
        int item = itemQue.front();
        itemQue.pop();
        res.push_back(item);
        for (auto graphItem :graph[item]) {
            if (inDegrees.find(graphItem) != inDegrees.end()) {
                inDegrees[graphItem]--;
                if (inDegrees[graphItem] == 0) {
                    itemQue.push(graphItem);
                }
            }
        }
    }
    if (org.size() != res.size()) {
        return false;
    }
    for (int i = 0; i < org.size(); i++) {
        if (org[i] != res[i]) {
            return false;
        }
    }
    return true;
}

#endif //LEETCODE_CPP_SEQRECONSTRUCTSLN_HPP
