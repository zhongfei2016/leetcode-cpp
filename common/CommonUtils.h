//
// leetcode-cpp
//

#ifndef LEETCODE_CPP_COMMONUTILS_H
#define LEETCODE_CPP_COMMONUTILS_H

#include <string>

class CommonUtils {
public:
    static void ExpectTrue(std::string name, bool result);

    static void ExpectFalse(std::string name, bool result);

    static void ExpectEqual(std::string name, int result1, int result2);
};


#endif //LEETCODE_CPP_COMMONUTILS_H
