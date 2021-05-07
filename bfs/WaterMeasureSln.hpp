// 水壶问题 https://leetcode-cn.com/problems/water-and-jug-problem/
#include <queue>
#include <unordered_set>

using namespace std;
/**
关于 std::unordered_set ：
std::unordered_set 与 std::set 的区别:
实现方面
std::unordered_set 是基于 hash 实现的。
std::set 是基于红黑树实现的。
遍历是否有序：
std::unordered_set 从名字可知不支持有序遍历。
std::set 可以有序遍历。
效率比较：
空间方面两者都是 o(n)o(n)。
时间方面，增删改查操作，set 都是 o(logn)，unordered_set 都是 o(1)o(1)。
 */
class WaterMeasureSln {
//    // 自定义对象的hash函数
//    struct StateHash {
//        size_t operator()(const State &state) const {
//            return (size_t(state.x) << 31) | size_t(state.y);
//        };
//    };
//
//    // 自定义对象的比较函数
//    struct StateCmp {
//        bool operator()(const State &lState, const State &rState) const {
//            return lState.x == rState.x && lState.y == rState.y;
//        }
//    };

public:
    bool canMeasureWater(int x, int y, int z);

    bool canMeasureWater2(int x, int y, int z);

private:
    pair<int, int> op(int type, const pair<int, int> &state, int x, int y);
};

inline int gcd(int a, int b) {
    int r;
    while (b > 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

bool WaterMeasureSln::canMeasureWater2(int x, int y, int z) {
    if (z == 0) {
        return true;
    }
    if (x + y < z) {
        return false;
    }
    if (x + y == z) {
        return true;
    }
    if (z % gcd(x, y) == 0) {
        return true;
    }
    return false;
}

inline int64_t Hash(int x, int y) {
    return int64_t(x) << 32 | y;
}

bool WaterMeasureSln::canMeasureWater(int x, int y, int z) {
    if (x + y < z) {   //加了一个很蠢的剪枝，作用比较大。
        return false;
    }
    unordered_set<int64_t> mark; //自定义hash算法，set里就直接存hash值
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    while (!q.empty()) {
        auto f = q.front();
        q.pop();
        if (f.first + f.second == z) {
            return true;
        }
        for (int i = 0; i < 6; i++) {
            auto next = op(i, f, x, y);
            int64_t h = Hash(next.first, next.second);
            if (mark.find(h) != mark.end()) {// unordered_set查找时间快，所以用unordered_set
                continue;
            }
            mark.insert(h);
            q.push(next);
        }
    }
    return false;
}

pair<int, int> WaterMeasureSln::op(int type, const pair<int, int> &state, int x, int y) {
    switch (type) {// 有六种方式
        case 0 :// x倒满，y保持现有值
            return make_pair(x, state.second);
        case 1 :// y倒满，x保持现有值
            return make_pair(state.first, y);
        case 2 :// x清空，y保持现有值
            return make_pair(0, state.second);
        case 3 :// y清空，x保持现有值
            return make_pair(state.first, 0);
        case 4 : {
            // 看下curX和y-curY的大小，目的也是看下能不能清空一个杯子，或者倒满一个杯子
            // curX小，说明可以把curX倒入y，这样可以清空x
            // y-curY小，说明可以将curX的一部分倒入y，倒满y
            int move = min(state.first, y - state.second);
            return make_pair(state.first - move, state.second + move);
        }
        case 5 : {
            // 看下curY和x-curX大小
            // curY小，就将y清空，即将curY都倒入x
            // x-curX小，就用curY将x倒满，y还剩一点
            int move = min(x - state.first, state.second);
            return make_pair(state.first + move, state.second - move);
        }
    }
    return make_pair(0, 0);
}