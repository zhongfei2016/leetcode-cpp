//
// leetcode-cpp
//

#ifndef LEETCODE_CPP_VALIDIPADDRSLN_H
#define LEETCODE_CPP_VALIDIPADDRSLN_H

#include <string>
#include <regex>

using namespace std;

class ValidIPAddrSln {
public:
    string validIPAddress2(string IP) {
        regex ipv4("(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])");
        regex ipv6("([0-9a-fA-F]{1,4}\\:){7}[0-9a-fA-F]{1,4}");
        if (regex_match(IP, ipv4)) return "IPv4";
        else if (regex_match(IP, ipv6)) return "IPv6";
        else return "Neither";
    }

    string validIPAddress(string IP) {
        string v4Sep = ".";
        string v6Sep = ":";
        if (IP.find(v4Sep) != string::npos) {
            vector<string> res = Split(IP, v4Sep);
            if (res.size() != 4) { return "Neither"; }
            for (auto &r : res) {
                if (r.size() == 0 || r.size() > 3 || (r[0] == '0' && r.size() > 1)) { return "Neither"; }
                for (auto &ch : r) {
                    if (!isdigit(ch)) { return "Neither"; }
                }
                if (std::stoi(r) > 255) { return "Neither"; }
            }
            return "IPv4";
        }
        if (IP.find(v6Sep) != string::npos) {
            vector<string> res = Split(IP, v6Sep);
            if (res.size() != 8) { return "Neither"; }
            regex rgx("^[0-9a-fA-F]{1,4}$");
            for (auto &r : res) {
                if (r.size() == 0 || r.size() > 4) { return "Neither"; }
                if (!regex_match(r, rgx)) { return "Neither"; }
            }
            return "IPv6";
        }
        return "Neither";
    }

private:
vector<string> Split(string &str, string &sep) {
    int idx = str.find(sep);
    int start = 0;
    vector<string> res;
    while (idx != string::npos) {
        res.push_back(str.substr(start, idx - start));
        start = idx + 1;
        idx = str.find(sep, start);
    }
    res.push_back(str.substr(start));
    return res;
}

};


#endif //LEETCODE_CPP_VALIDIPADDRSLN_H
