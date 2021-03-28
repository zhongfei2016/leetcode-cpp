#include <iostream>

#include <algorithm>
#include <set>
#include <map>
#include <iterator>
#include <vector>

using namespace std;

int main() {
    std::set<int> testSet = {0, 0, 1, 2, 0, 4, 6, 8, 0, 0, 0, 9, 10, 0};
    for (auto iter = testSet.begin(); iter != testSet.end();) {
        if (*iter == 0) {
            iter = testSet.erase(iter);
        } else {
            iter++;
        }
    }
    for (auto item : testSet) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    vector<int> testVector = {0, 0, 1, 2, 0, 4, 6, 8, 0, 0, 0, 9, 10, 0};
    for (auto iter = testVector.begin(); iter != testVector.end();) {
        if (*iter == 0) {
            iter = testVector.erase(iter);
        } else {
            iter++;
        }
    }
    for (auto item : testVector) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    std::map<int, int> testMap = {{1, 9},
                                  {2, 5},
                                  {0, 1},
                                  {5, 8},
                                  {3, 9},
                                  {0, 1},
                                  {2, 7},
                                  {4, 5},
                                  {1, 0}};
    for (auto iter = testMap.begin(); iter != testMap.end();) {
        if (iter->first < 4) {
            iter = testMap.erase(iter);
        } else {
            iter++;
        }
    }
    for (auto item : testMap) {
        std::cout << item.first << ":" << item.second << std::endl;
    }
    std::vector<int> copyVec{1, 2, 3, 4, 5, 3};
    std::copy(copyVec.begin(), copyVec.end(), std::ostream_iterator<int>(cout, " "));
    cout << endl;
    std::reverse(copyVec.begin(), copyVec.end());// 3,5,4,3,2,1
    std::rotate(copyVec.begin(), copyVec.begin() + 2, copyVec.end());//4,3,2,1,3,5
    std::copy(copyVec.begin() + 1, copyVec.begin() + 6, copyVec.begin());// 3,2,1,3,5,5
    std::next_permutation(copyVec.begin(), copyVec.end());// 3,2,1,5,3,5
    std::fill(copyVec.begin(), copyVec.end(), 0); // 0,0,0,0,0,0
    // inner_product 内积计算 http://c.biancheng.net/view/683.html
    return 0;
}
