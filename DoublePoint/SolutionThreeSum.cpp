//
// Created by fei on 2019/12/22.
//

#include "SolutionThreeSum.h"

void mergeVec(vector<int> &vec, int left, int mid, int right) {
    int pLeft = left;
    int pRight = mid + 1;
    vector<int> temp;
    while (pLeft <= mid && pRight <= right) {
        temp.push_back(vec[pLeft] < vec[pRight] ? vec[pLeft++] : vec[pRight++]);
    }
    while (pLeft <= mid) {
        temp.push_back(vec[pLeft++]);
    }

    while (pRight <= right) {
        temp.push_back(vec[pRight++]);
    }
    for (int i = left, cnt = 0; cnt < temp.size(); i++, cnt++) {
        vec[i] = temp[cnt];
    }
}

void merge(vector<int> &vec, int left, int right) {
    if (right == left) {
        return;
    }
    int mid = left + ((right - left) >> 1);
    merge(vec, left, mid);
    merge(vec, mid + 1, right);
    mergeVec(vec, left, mid, right);
}

/**
 * 思路：先排序，然后将起始数字作为基数，必须是小于等于0的，否则和后面的数求和无法得到0
 * 并且起始数字下标要排除后面的low和high下标，所以now下标小于数组size-2
 * 每次求now，low，high下标对应数字的和，大于0说明high对应的数字大了，high--，小于0说明low对应的数字小了，low++
 * 等于0就加到res结果集里，并且low和high下标对应的数字要去重
 * now下标也要去重
 * @param nums
 * @return
 */
vector<vector<int> > SolutionThreeSum::threeSum(vector<int> &nums) {
    vector<vector<int> > res;
    if (nums.size() <= 2) {
        return res;
    }
    vector<int> temp;
    temp.insert(temp.end(), nums.begin(), nums.end());
    int size = temp.size();
    int low = 1;
    int high = size - 1;
    merge(temp, 0, size - 1);
    int now = 0;
    vector<int> three;
    for (; temp[now] <= 0 && now<size-2; now++) {
        low = now + 1;
        high = size - 1;
        while (low < high) {
            int lowVal = temp[low];
            int highVal = temp[high];
            if (temp[now] + lowVal + highVal > 0) {
                high--;
            } else if (temp[now] + lowVal + highVal < 0) {
                low++;
            } else {
                three.clear();
                three.push_back(temp[now]);
                three.push_back(lowVal);
                three.push_back(highVal);
                res.push_back(three);
                while (low < high && temp[low] == lowVal) {
                    low++;
                }
                while (low < high && temp[high] == highVal) {
                    high--;
                }
            }
        }
        // now下标都要小于size-2，所以now+1要想作为下一个now，也要小于size-2
        while ((now + 1 < size - 2) && temp[now] == temp[now + 1]) {
            now++;
        }
    }
    return res;
}