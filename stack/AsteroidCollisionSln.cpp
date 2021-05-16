//
//
//

#include <cmath>
#include "AsteroidCollisionSln.h"

vector<int> AsteroidCollisionSln::asteroidCollision(vector<int> &asteroids) {
    vector<int> results;
    for (int i = 0; i < asteroids.size(); i++) {
        bool isAdd = true;
        while (!results.empty() && results.back() > 0 && asteroids[i] < 0) {
            if (abs(results.back()) > abs(asteroids[i])) {
                isAdd = false;
                break;
            } else if (abs(results.back()) == abs(asteroids[i])) {
                results.pop_back();
                isAdd = false;
                break;
            } else {
                results.pop_back();
                continue;
            }
        }
        if (isAdd) {
            results.push_back(asteroids[i]);
        }
    }
    return results;
}
