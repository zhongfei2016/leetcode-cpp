//
// leetcode-cpp
//

#include "NaturalSortSln.h"

bool NaturalSortSln::NaturalCompare() {
    assert(alphanum_comp("","") == 0);
    assert(alphanum_comp("","a") < 0);
    assert(alphanum_comp("a","") > 0);
    assert(alphanum_comp("a","a") == 0);
    assert(alphanum_comp("","9") < 0);
    assert(alphanum_comp("9","") > 0);
    assert(alphanum_comp("1","1") == 0);
    assert(alphanum_comp("1","2") < 0);
    assert(alphanum_comp("3","2") > 0);
    assert(alphanum_comp("a1","a1") == 0);
    assert(alphanum_comp("a1","a2") < 0);
    assert(alphanum_comp("a2","a1") > 0);
    assert(alphanum_comp("a1a2","a1a3") < 0);
    assert(alphanum_comp("a1a2","a1a0") > 0);
    assert(alphanum_comp("134","122") > 0);
    assert(alphanum_comp("12a3","12a3") == 0);
    assert(alphanum_comp("12a1","12a0") > 0);
    assert(alphanum_comp("12a1","12a2") < 0);
    assert(alphanum_comp("a","aa") < 0);
    assert(alphanum_comp("aaa","aa") > 0);
    assert(alphanum_comp("Alpha 2","Alpha 2") == 0);
    assert(alphanum_comp("Alpha 2","Alpha 2A") < 0);
    assert(alphanum_comp("Alpha 2 B","Alpha 2") > 0);

    assert(alphanum_comp(1,1) == 0);
    assert(alphanum_comp(1,2) < 0);
    assert(alphanum_comp(2,1) > 0);
    assert(alphanum_comp(1.2,3.14) < 0);
    assert(alphanum_comp(3.14,2.71) > 0);
    assert(alphanum_comp(true,true) == 0);
    assert(alphanum_comp(true,false) > 0);
    assert(alphanum_comp(false,true) < 0);

    std::string str("Alpha 2");
    assert(alphanum_comp(str,"Alpha 2") == 0);
    assert(alphanum_comp(str,"Alpha 2A") < 0);
    assert(alphanum_comp("Alpha 2 B",str) > 0);
    return true;
}