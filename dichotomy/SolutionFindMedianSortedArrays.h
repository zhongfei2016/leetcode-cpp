//
// Created by fei on 2019/12/22.
//

#ifndef CPPTEST_SOLUTIONFINDMEDIANSORTEDARRAYS_H
#define CPPTEST_SOLUTIONFINDMEDIANSORTEDARRAYS_H

#include <vector>

using namespace std;

class SolutionFindMedianSortedArrays {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
    double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2);

private:
    void merge(vector<int> &vec, int left, int right);
    void mergeVec(vector<int> &vec, int left, int mid, int right);
};


#endif //CPPTEST_SOLUTIONFINDMEDIANSORTEDARRAYS_H
