//
// leetcode-cpp
//

#include <cmath>
#include "FindInMountainArraySln.h"

int MountainArray::get(int index) {
    if (index >= m_arr.size()) {
        return -1;
    }
    return m_arr[index];
}

int MountainArray::length() {
    return m_arr.size();
}

int FindInMountainArraySln::findInMountainArray(int target, MountainArray &mountainArr) {
    int low = 0;
    int high = mountainArr.length() - 1;
    int mountainIdx = findMountainTopIdx(mountainArr, low, high);
    int res = findIncreaseTargetIdx(mountainArr, target, 0, mountainIdx);
    if (res != -1) {
        return res;
    }
    res = findDecreaseTargetIdx(mountainArr, target, mountainIdx, high);
    return res;
}

int FindInMountainArraySln::findMountainTopIdx(MountainArray &mountainArray, int left, int right) {
    int mountainIdx = -1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        int curHeight = mountainArray.get(mid);
        int nextHeight = mountainArray.get(mid + 1);
        if (curHeight < nextHeight) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    mountainIdx = left;
    return mountainIdx;
}

int FindInMountainArraySln::findIncreaseTargetIdx(MountainArray &mountainArray, int target, int left, int right) {
    while (left < right) {
        int mid = left + (right - left) / 2;
        int curHeight = mountainArray.get(mid);
        if (curHeight == target) {
            return mid;
        }
        if (curHeight < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (mountainArray.get(left) == target) {
        return left;
    }
    return -1;
}

int FindInMountainArraySln::findDecreaseTargetIdx(MountainArray &mountainArray, int target, int left, int right) {
    while (left < right) {
        int mid = left + (right - left) / 2;
        int curHeight = mountainArray.get(mid);
        if (curHeight == target) {
            return mid;
        }
        if (curHeight < target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    // 如果left和right挨着，mid肯定是left的值，right-1之后顶多还是取mid也就是left的值
    // 而之前left也就是mid值已经被判断过，所以right=mid-1小于等于left后，其值已被判断过
    // 无需再次判断，而left如果变为mid+1超过了right，则未判断，需要额外判断一次
    if (mountainArray.get(left) == target) {
        return left;
    }
    return -1;
}
