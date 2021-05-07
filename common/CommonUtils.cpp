//
// leetcode-cpp
//

#include "CommonUtils.h"

#include <iostream>

void CommonUtils::ExpectTrue(std::string name, bool result) {
    if (!result) {
        std::cerr << name << " result expect true, but result is " << result << std::endl;
    }
}

void CommonUtils::ExpectFalse(std::string name, bool result) {
    if (result) {
        std::cerr << name << " result expect false, but result is " << result << std::endl;
    }
}

void CommonUtils::ExpectEqual(std::string name, int result1, int result2) {
    if (result1 != result2) {
        std::cerr << name << " result expect result1 == result2, but result1 is " << result1 << ", result2 is "
                  << result2 << std::endl;
    }
}