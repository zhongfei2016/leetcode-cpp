//
// leetcode-cpp
//

#include "MinDistanceSolution.h"

int minFun(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

int MinDistanceSolution::minDistance(string word1, string word2) {
    //首先第一行和第一列的是边界条件，由于dp[i][j] 表示 word1 的前 i 个字母和 word2 的前 j 个字母之间的编辑距离
    // 所以dp[i][0]表示第一个单词每个字母对应空串的编辑举例，所以每多一个字母就+1，dp[0][j]也是这个含义
    //
    // d[i][j]的实现有三种方法：
    //第一个单词的前i位变成第二个单词的前j-1位，然后再插入一个字符（d[i][j-1]+1）
    //第一个单词的前i-1位变成第二个单词的前j位，然后再删去一个字符（d[i-1][j]+1）
    //第一个单词的前i-1位变成第二个单词的前j-1位，然后替换最后一个字符，如果最后一个字符相同，即第一个单词的第i位和第二个单词的第j位相同的话，就不用替换了（d[i-1][j-1]），反之，如果不同就替换最后一位（d[i-1][j-1]+1）
    //因为我们需要的是第一个单词前i位到第二个单词前j位的最短编辑路径，所以就在这三种方案中取最小值就行了
    int m = word1.length();
    int n = word2.length();
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = minFun(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
            }
        }
    }
    return dp[m][n];
}