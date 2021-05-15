//
// leetcode-cpp
//

#ifndef LEETCODE_CPP_FINDINMOUNTAINARRAYSLN_H
#define LEETCODE_CPP_FINDINMOUNTAINARRAYSLN_H

#include <vector>

using namespace std;

class MountainArray {
public:
    MountainArray(vector<int> arr) : m_arr(arr) {};

    int get(int index);

    int length();

private:
    vector<int> m_arr;
};

class FindInMountainArraySln {
public:
    int findInMountainArray(int target, MountainArray &mountainArr);

    int findMountainTopIdx(MountainArray &mountainArray, int left, int right);

    int findIncreaseTargetIdx(MountainArray &mountainArray, int target, int left, int right);

    int findDecreaseTargetIdx(MountainArray &mountainArray, int target, int left, int right);
};


#endif //LEETCODE_CPP_FINDINMOUNTAINARRAYSLN_H
