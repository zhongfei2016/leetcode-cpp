//
// Created by ZHONGFEI on 2020/4/5.
//

#include "CountSubstrSln.h"

#include <vector>

using namespace std;

/**
 * 回文数统计，dp动态规划方式
 * @param s
 * @return
 */
int CountSubstrSln::countSubstrings(string s) {
    // 字符串长度为0则没有回文子串，为1则只有一个回文子串，就是他自己，因为每一个字母都是一个回文子串
    if (s.size() == 0) { return 0; }
    if (s.size() == 1) { return 1; }

    int res = 0;
    //dp表示从i~j的子字符串是否是回文字符串的标志，是为true，不是为false
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    // 斜着遍历，j从0到n，i跟在后面从j到0，遍历dp矩阵里的左下三角
    /**
     * #  |     #    |    #    |    #        #
     * #  |  i=j=0   |         |
     * #  | j=1,i=0  |  i=j=1  |
     * #  | j=2,i=0  | j=2,i=1 |  i=j=2
     * #  | j=3,i=0  | j=3,i=1 | j=3,i=2  | i=j=3
     */
    for (int j = 0; j < s.size(); j++) {
        for (int i = j; i >= 0; i--) {
            // 从i=j开始，i往左移，如果s[i] == s[j]表示当前字符为回文子串
            if (s[i] == s[j]) {
                //相差1，说明是间隔的两个字符，直接判断为回文
                if (j - i <= 1) {
                    dp[i][j] = true;
                    res++;
                    continue;
                }
                // 否则，就要i和j各向内走一个，如果还是回文，则dp[i][j]也是回文
                if ((dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    res++;
                    continue;
                }
            }
        }
    }
    return res;
}