#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status:
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int brokenCalc(int startValue, int target, int count = 0) {
        if (startValue == target) {
            return count;
        }
        return min(brokenCalc(startValue * 2, target, count + 1), brokenCalc(startValue - 1, target, count + 1));
    }
};