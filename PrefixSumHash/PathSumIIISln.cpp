//
// leetcode-cpp
//

#include <unordered_map>
#include "PathSumIIISln.h"

//               |----target----|
//———————————————|——————————————|——————
//        curSum-target      curSum
// 在得到curSum时，看看有多少个curSum-target，就有多少种结果
// 然后再把curSum作为一个curSum-target，继续往子节点看，得到结果后，再把curSum剔除掉
int
PathSumIIISln::countNodeResult(TreeNode *curNode, std::unordered_map<int, int> &sumCountMap, int srcSum, int target) {
    if (curNode == nullptr) { return 0; }
    int curSum = srcSum + curNode->val;
    auto mapIter = sumCountMap.find(curSum - target);
    int result = mapIter != sumCountMap.end() ? mapIter->second : 0;
    sumCountMap[curSum]++;
    result += countNodeResult(curNode->left, sumCountMap, curSum, target);
    result += countNodeResult(curNode->right, sumCountMap, curSum, target);
    sumCountMap[curSum]--;
    return result;
}

// 前缀和
int PathSumIIISln::pathSum(struct TreeNode *root, int sum) {
    std::unordered_map<int, int> sumCountMap;
    sumCountMap[0] = 1;// 当前节点的值==targetSum，所以此节点本身就是一个有效路径，要把这种路径记上
    int result = countNodeResult(root, sumCountMap, 0, sum);
    return result;
}

int PathSumIIISln::pathSum2(TreeNode *root, int sum) {
    int result = dfs(root, sum);
    return result;
}

// 第二次递归是以root节点开始往下遍历，能将num清零的即为一个路径
int PathSumIIISln::countPath(TreeNode *root, int num) {
    if (root == nullptr) {
        return 0;
    }
    int result = 0;
    if (root->val == num) {
        result++;
    }
    result += countPath(root->left, num - root->val);
    result += countPath(root->right, num - root->val);
    return result;
}

// 递归方式，双层递归，第一层是递归每一个节点
// 用每一个节点作为根节点计算能得到targe的路径个数
int PathSumIIISln::dfs(TreeNode *root, int target) {
    if (root == nullptr) {
        return 0;
    }
    // 计算以每一个节点作为根节点时能得到target的路径个数
    int result = countPath(root, target);
    result += dfs(root->left, target);
    result += dfs(root->right, target);
    return result;
}
