//
// Created by fei on 2019/12/22.
//

#include "SolutionLongestPalindrome.h"

// 以左右为中心向两边扩展最大的回文数
string centerSpread(string str, int left, int right){
    int i = left;
    int j = right;
    while(i>=0 && j<str.size()){
        if(str[i] == str[j]){
            i--;
            j++;
        }
        else{
            break;
        }
    }
    return str.substr(i+1,j-i-1);
}

string SolutionLongestPalindrome::longestPalindrome(string s) {
    if(s.size()<2){
        return s;
    }
    int maxLen = 1;
    string maxStr = s.substr(0,1);
    for(int i=0;i<s.size()-1;i++){
        string oddstr = centerSpread(s,i,i);
        string evenstr = centerSpread(s,i,i+1);
        string tempMax = oddstr.size()>evenstr.size()?oddstr:evenstr;
        if(tempMax.size() > maxLen){
            maxStr = tempMax;
            maxLen = tempMax.size();
        }
    }
    return maxStr;
}