//
// leetcode-cpp
//

#include "NumTreesSolution.h"

#include <vector>

using namespace std;

int NumTreesSolution::numTrees(int n) {
    // 动态规划，用到两个公式G(n)和F(i,n)
    // 其中G(n)表示以1~n的每一个数作为根节点的总种类数，F(i,n)表示以i为根节点的种类数
    // 所以G(n) = F(1,n)+F(2,n)+...+F(n,n), 而F(i,n) = G(i-1)*G(n-i)，
    // 因为F(i,n)表示以i作为根节点所有种类，它可以分为左子树和右子树两段，
    // 左子树是以1~i-1每个数为根的所有种类，右子树是以i+1~n即1~n-i每个数为根的所有种类
    // 两端的笛卡尔积就是F(i,n)
    // 所以G(n)=G(0)*G(n-1)+G(1)*G(n-2)+...+G(n-1)*G(0)
    // 动态规划，就是把问题拆分成规模较小的问题，然后存储并复用上一个子问题的解
    vector<int> g(n + 1, 0);
    if (n <= 1) {
        return 1;
    }
    g[0] = 1;
    g[1] = 1;
    // i就是每一层的n，因为0和1都是1，是已知的，所以从2开始
    for (int i = 2; i <= n; i++) {
        // idx是每一个要作为根节点的数，从1到每一层的n
        for (int idx = 1; idx <= i; idx++) {
            g[i] += g[idx - 1] * g[i - idx];
        }
    }
    return g[n];
}


// dfs实现
int NumTreesSolution::numTrees2(int n) {
    vector<int> memos(n + 1, 0);
    int res = dfs(n, memos);
    return res;
}

int NumTreesSolution::dfs(int n, vector<int> &memos) {
    if (n == 0 || n == 1) {
        return 1;
    }
    if (memos[n] != 0) {
        return memos[n];
    }
    int maxNum = 0;
    for (int j = 1; j <= n; j++) {
        // j-1个左子树，n-j个右子树，左子树和右子树的乘积就是以j为根的不同二叉树的和，j取值为1到n
        maxNum += dfs(j - 1, memos) * dfs(n - j, memos);
    }
    memos[n] = maxNum;
    return maxNum;
}
