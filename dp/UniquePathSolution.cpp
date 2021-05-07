//
// leetcode-cpp
//

#include "UniquePathSolution.h"

int backTrack(int m, int n) {
    if(m <= 0 || n <= 0) return 0;
    if(m == 1 || n == 1) return 1; //只能一直向右走或向下走，所以路径数为 1
    return backTrack(m-1,n)+backTrack(m,n-1);
}

// 深度遍历
void backTrack(int a, int b, int m, int n, int &cnt) {
    if (a == m && b == n) {
        cnt = cnt + 1;
        return;
    }
    if (a < m) {
        backTrack(a + 1, b, m, n, cnt);
    }
    if (b < n) {
        backTrack(a, b + 1, m, n, cnt);
    }
}

int UniquePathSolution::uniquePaths(int m, int n) {
    int cnt = 0;
    // 递归方式，会超时
//    cnt = backTrack(m, n);
//    backTrack(1,1,m, n,cnt);
    int dp[m][n];
    for (int i = 0; i < m; i++) {
        dp[i][0] = 1;
    }
    for (int j = 0; j < n; j++) {
        dp[0][j] = 1;
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    cnt = dp[m - 1][n - 1];
    return cnt;
}
