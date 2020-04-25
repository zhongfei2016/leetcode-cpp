// https://leetcode-cn.com/problems/water-and-jug-problem/
#include <queue>
#include <unordered_set>

using namespace std;

class WaterMeasureSln {
    struct State {
        State(int x, int y) {
            this->x = x;
            this->y = y;
        }

        int x;
        int y;
    };

    // 自定义对象的hash函数
    struct StateHash {
        size_t operator()(const State &state) const {
            return (size_t(state.x) << 31) | size_t(state.y);
        };
    };

    // 自定义对象的比较函数
    struct StateCmp {
        bool operator()(const State &lState, const State &rState) const {
            return lState.x == rState.x && lState.y == rState.y;
        }
    };

public:
    bool canMeasureWater(int x, int y, int z);

    bool canMeasureWater2(int x, int y, int z);

private:
    vector<State> GetNextStates(int curX, int curY, int x, int y);
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

bool WaterMeasureSln::canMeasureWater(int x, int y, int z) {
    if (z == 0) {
        return true;
    }
    if (x + y < z) {
        return false;
    }
    queue<State> que;
    unordered_set<State, StateHash, StateCmp> visitSet;
    State initState(0, 0);
    que.push(initState);
    visitSet.insert(initState);
    while (!que.empty()) {
        auto state = que.front();
        que.pop();
        int curX = state.x;
        int curY = state.y;
        if (curX == z || curY == z || curX + curY == z) {
            return true;
        }
        vector<State> nextStates = GetNextStates(curX, curY, x, y);
        for (auto &nextState : nextStates) {
            if (visitSet.find(nextState) == visitSet.end()) {
                que.push(nextState);
                visitSet.insert(nextState);
            }
        }
    }
    return false;
}

vector<WaterMeasureSln::State> WaterMeasureSln::GetNextStates(int curX, int curY, int x, int y) {
    vector<WaterMeasureSln::State> nextStates;
    // 分八种情况讨论
    // 1、curX少于x满额值时把X倒满
    if (curX < x) {
        State state(x, curY);
        nextStates.push_back(state);
    }
    // 2、curY少于y满额值时把Y倒满
    if (curY < y) {
        State state(curX, y);
        nextStates.push_back(state);
    }
    // X有水时把X清空
    if (curX > 0) {
        State state(0, curY);
        nextStates.push_back(state);
    }
    // Y有水时把Y清空
    if (curY > 0) {
        State state(curX, 0);
        nextStates.push_back(state);
    }
    // X的水倒入Y，Y满，X有剩余
    if (curX - (y - curY) > 0) {
        State state(curX - (y - curY), y);
        nextStates.push_back(state);
    }
    // 同样X倒入Y，但Y不满，X倒空
    if (curX + curY < y) {
        State state(0, curX + curY);
        nextStates.push_back(state);
    }
    // Y的水倒入X，X满，Y有剩余
    if (curY - (x - curX) > 0) {
        State state(x, curY - (x - curX));
        nextStates.push_back(state);
    }
    // 同样Y倒入X，但X不满，Y倒空
    if (curX + curY < x) {
        State state(curX + curY, 0);
        nextStates.push_back(state);
    }
    return nextStates;
}