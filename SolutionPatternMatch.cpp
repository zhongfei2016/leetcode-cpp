//
// Created by fei on 2019/12/22.
//

#include "SolutionPatternMatch.h"

bool SolutionPatternMatch::isMatch(string s, string p) {
    // pattern为空那s一定要为空，但s为空，pattern可以是.*或者a*等
    if (p.empty()) {
        return s.empty();
    }
    bool firstMatch = (s[0] == p[0]) || (p[0] == '.');

    // 只有pattern长度大于2时*才有意义，不然pattern长度为1还有*，也就只是一个*，没有前一个字符还是什么都匹配不上
    if (p.size() >= 2 && p[1] == '*') {
        if (s.empty()) {
            // 如果此时s已经空了，那p.sub(2)应该什么都没有或者再继续是.*或a*等等，不能再继续裁s了，避免s.substr(1)越界
            return isMatch(s, p.substr(2));
        }
        // 要么s前面是不匹配p的*前面的内容，比如s=ccda，p=a*ccda
        // 要么就是第一个匹配，后面将s减一个再次跟p匹配
        return isMatch(s, p.substr(2)) || (firstMatch && isMatch(s.substr(1), p));
    } else {
        if(s.empty()){
            //此时p肯定不是空，第一行已经判断，p又不是a*或者.*等格式，不支持空串，而s空了，所以直接返回false，不再判断，避免后面s.substr(1)越界
            return false;
        }
        return firstMatch && isMatch(s.substr(1), p.substr(1));
    }
}