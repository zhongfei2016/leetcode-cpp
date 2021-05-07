//
// leetcode-cpp
//
#include "SuffixOperationSln.h"


int main() {
    // 中缀表达式转成后缀表达式并计算结果
    SuffixOperationSln suffixOperationSln;
    double resultSuffix = suffixOperationSln.CalOperation("1+((21+315)*40)-15");
    return 0;
}