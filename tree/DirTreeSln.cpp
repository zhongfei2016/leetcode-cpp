//
// leetcode-cpp
//

#include <map>
#include "DirTreeSln.h"

/**
 * |-B
 * A
 * |-B
 * |-|-B
 * |-C
 * |-lib
 * |-|-|-C
 * |-|-D
 * |-|-|-E
 * @param dirs
 * @return
 */
class StrNode *DirTreeSln::BuildNodeTree(vector<std::string> &dirs) {
    int toFindIdx = 0;
    StrNode *root = new StrNode();
    std::map<int, StrNode *> dirMap;
    for (auto &dir : dirs) {
        int idx = getIdx(dir);
        string name = getDirName(dir);
        if (idx > toFindIdx) {
            continue;
        }
        if (idx == 0) {
            root->val = name;
            toFindIdx++;
            dirMap[0] = root;
            continue;
        }
        auto fatherDirIter = dirMap.find(idx - 1);
        StrNode *curNode = new StrNode();
        curNode->val = name;
        dirMap[idx] = curNode;
        bool needAdd = true;
        for (const auto &child: fatherDirIter->second->children) {
            if (child->val == curNode->val) {
                needAdd = false;
                break;
            }
        }
        if (needAdd) {
            fatherDirIter->second->children.push_back(curNode);
            toFindIdx = max(toFindIdx, idx + 1);
        }
    }
    return root;
}

std::string DirTreeSln::getDirName(std::string dir) {
    auto idx = dir.find_first_not_of("|-");
    return dir.substr(idx);
}

int DirTreeSln::getIdx(std::string dir) {
    auto idx = dir.find_first_not_of("|-");
    return (static_cast<int>(idx) + 1) / 2;
}

bool DirTreeSln::dfsDeleteDirs(StrNode *parent, const unordered_set<string> &delDirs, vector<string> &result) {
    if (parent == nullptr) {
        return false;
    }
    for (auto iter = parent->children.begin(); iter != parent->children.end();) {
        if (dfsDeleteDirs(*iter, delDirs, result)) {
            iter = parent->children.erase(iter);
        } else {
            iter++;
        }
    }
    if (parent->children.empty()) {
        if (delDirs.find(parent->val) != delDirs.end()) {
            result.push_back(parent->val);
            return true;
        }
    }
    return false;
}
