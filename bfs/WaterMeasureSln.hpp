// 水壶问题 https://leetcode-cn.com/problems/water-and-jug-problem/
#include <queue>
#include <unordered_set>

using namespace std;

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
    unordered_set<int64_t> mark; //pair<int, int> 换成int64_t, 但是意义不大。
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    while (q.empty() == false) {
        auto f = q.front();
        q.pop();
        if (f.first + f.second == z) {
            return true;
        }
        for (int i = 0; i < 6; i++) {
            auto next = op(i, f, x, y);
            int64_t h = Hash(next.first, next.second);
            if (mark.find(h) != mark.end()) {
                continue;
            }
            mark.insert(h);
            q.push(next);
        }
    }
    return false;
}

pair<int, int> WaterMeasureSln::op(int type, const pair<int, int> &state, int x, int y) {
    switch (type) {
        case 0 :
            return make_pair(x, state.second);
        case 1 :
            return make_pair(state.first, y);
        case 2 :
            return make_pair(0, state.second);
        case 3 :
            return make_pair(state.first, 0);
        case 4 : {
            // 看下curX和y-curY的大小，curX小，说明可以清空x，倒入y，y-curY小，说明可以将x的一部分倒入y，倒满y
            int move = min(state.first, y - state.second);
            return make_pair(state.first - move, state.second + move);
        }
        case 5 : {
            int move = min(x - state.first, state.second);
            return make_pair(state.first + move, state.second - move);
        }
    }
    return make_pair(0, 0);
}