//
// Created by ZHONGFEI on 2020/1/31.
//

#include "ClimbStairSolution.h"

int ClimbStairSolution::climbStairs(int n) {
    if(n<3){
        return n;
    }
    int stair[n+1];
    stair[0]=0;
    stair[1]=1;
    stair[2]=2;
    for(int i=3;i<=n;i++) {
        stair[i] = stair[i-1]+stair[i-2];
    }
    return stair[n];
}