//
// Created by ZHONGFEI on 2021/3/26.
//
#include "SolutionLongestPalindrome.h"
#include "LongestPalindromeSln.hpp"
#include "RestoreIPAddrSln.hpp"
#include "NumConvertSln.h"
#include "StringConvertSln.h"
#include "MaxSameStrSln.h"
#include "MaxUnduplicateStrSln.h"
#include "ValidIPAddrSln.h"
#include "MultiStringSln.h"
#include "GroupAnagramsSolution.h"
#include "LuckFibonacciStrSln.h"
#include "AddBinarySln.h"
#include "ConvertZSln.h"
#include "InsertDigitalSln.h"

using namespace std;

int main() {
// 最长不含重复字符的子字符串
    MaxUnduplicateStrSln maxUnduplicateStrSln;
    maxUnduplicateStrSln.lengthOfLongestSubstring("bbbbb");

    MaxSameStrSln maxSameStrSln;
    maxSameStrSln.maxSameStr("abcadgbcs", "vavcadgbccacsvb");

    // 最长回文子串 https://leetcode-cn.com/problems/longest-palindromic-substring/
    SolutionLongestPalindrome lp;
    lp.longestPalindrome("aaaa");

    // 最长回文串 取给定字符串的字符凑最长回文串 https://leetcode-cn.com/problems/longest-palindrome/
    LongestPalindromeSln longestPalindromeSln;
    longestPalindromeSln.longestPalindrome("abccccdd");

    // 字母异位词分组 https://leetcode-cn.com/problems/group-anagrams/
    vector<string> groupAnaVec = {"eat", "tea", "tan", "ate", "nat", "bat"};
    GroupAnagramsSolution groupAnaSln;
    groupAnaSln.groupAnagrams(groupAnaVec);

    // 符合斐波那契数列的子字符串
    LuckFibonacciStrSln luckFibonacciStrSln;
    luckFibonacciStrSln.ListLuckFiboSubStr("aabcd");

    // 复原IP地址，dfs深度遍历 https://leetcode-cn.com/problems/restore-ip-addresses/
    RestoreIPAddrSln restoreIpAddrSln;
    restoreIpAddrSln.restoreIpAddresses("25525511135");

    NumConvertSln numConvertSln;
    numConvertSln.NumConvertTest();

    StringConvertSln stringConvertSln;
    stringConvertSln.StringConvertTest();

    ValidIPAddrSln validIpAddrSln;
    validIpAddrSln.validIPAddress("172.16.254.1");
    validIpAddrSln.validIPAddress("2001:0db8:85a3:0000:0000:8a2e:0370:7334");

    MultiStringSln multiStringSln;
    multiStringSln.multiply("123", "456");

    // 二进制求和 https://leetcode-cn.com/problems/add-binary/
    AddBinarySln addBinarySln;
    string addBinStr1 = addBinarySln.addBinary("101", "10111");
    string addBinStr2 = addBinarySln.addBinary(
            "10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101",
            "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011");
    vector<char> reverseVec = {'H'};
    // 使用双指针翻转字符串
    addBinarySln.reverseString(reverseVec);

    ConvertZSln convertZSln;
    convertZSln.convert("PAYPALISHIRING", 3);

    InsertDigitalSln insertDigitalSln;
    insertDigitalSln.insertDigit("8784","785");
    insertDigitalSln.insertDigit("8988349","88349");
    return 0;
}