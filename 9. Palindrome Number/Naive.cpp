#include <bits/stdc++.h>
using namespace std;

/*
    Approach: Using String
        First convert the number into string and then compare it withs its reverse

   Edge Cases:


   Time Complexity: O(log(n)) Space: O(1)
   Status: Accepted
   Runtime: 16 ms faster than: 56.94%
   Memory Usage: 5.9 MB less than: 31.60%
*/

class Solution {
   public:
    bool isPalindrome(int x) {
        string num, revNum;
        revNum = num = to_string(x);
        reverse(revNum.begin(), revNum.end());
        if (num == revNum) {
            return true;
        }
        return false;
    }
};