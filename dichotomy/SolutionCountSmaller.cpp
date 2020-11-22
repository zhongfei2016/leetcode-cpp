//
// Created by fei on 2019/12/21.
//
#include "SolutionCountSmaller.h"

vector<int> SolutionCountSmaller::countSmaller(vector<int> &nums) {
    vector<int> count;
    vector<pair<int, int>> vec;
    for (int i = 0; i < nums.size(); i++) {
        vec.push_back(make_pair(nums[i], i));
        count.push_back(0);
    }
    merge(vec, count);
    return count;
}

void SolutionCountSmaller::mergeTwo(vector<pair<int, int>> &sub_vec1, vector<pair<int, int>> &sub_vec2,
                                    vector<pair<int, int>> &vec, vector<int>& count) {
    int i =0;
    int j =0;
    while(i < sub_vec1.size() && j < sub_vec2.size())
    {
        if(sub_vec1[i].first <= sub_vec2[j].first )
        {
            vec.push_back(sub_vec1[i]);
            // 只计算左侧，因为左侧天然符合索引小于右侧，且两边天然有序，不需要考虑左侧当前数和其他数的大小关系
            // 这时候只需判断，如果右侧小就赋值，但是要累加，因为每层都会统计，右侧大j+1，等待下一次右侧小累加
            count[sub_vec1[i].second] += j;//这句话和下面注释的地方就是这道题和归并排序的主要不同之处
            i++;
        }else{
            vec.push_back(sub_vec2[j]);
            j++;
        }
    }

    for(;i<sub_vec1.size();++i)
    {
        // 如果左侧有剩余，那都要累加j，因为左侧此时剩余的数都有j个他右侧的数比他小
        vec.push_back(sub_vec1[i]);
        count[sub_vec1[i].second] += j;// -。-
    }
    for(;j<sub_vec2.size();++j)
    {
        vec.push_back(sub_vec2[j]);
    }
}

void SolutionCountSmaller::merge(vector<pair<int, int>> &vec, vector<int>& count) {
    if (vec.size() < 2) {
        return;
    }
    int len = vec.size();
    int mid = len / 2;
    vector<pair<int, int>> subVec1;
    vector<pair<int, int>> subVec2;
    for (int i = 0; i < mid; i++) {
        subVec1.push_back(vec[i]);
    }
    for (int i = mid; i < len; i++) {
        subVec2.push_back(vec[i]);
    }
    merge(subVec1, count);
    merge(subVec2, count);
    vec.clear();
    mergeTwo(subVec1, subVec2, vec, count);
}