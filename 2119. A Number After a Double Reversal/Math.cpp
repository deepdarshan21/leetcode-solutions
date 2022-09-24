#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Math

   Edge Cases:

   Time Complexity: O(1) Space: O(1)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 5.7 MB less than: 98.73%
   Remarks:
*/

class Solution {
   public:
    bool isSameAfterReversals(int num) {
        if (num == 0) return true;
        return num % 10 == 0 ? false : true;
    }
};