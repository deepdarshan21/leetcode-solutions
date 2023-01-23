#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Wrong answer
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int reachNumber(int target) {
        int res = 0;
        int curr = 0;
        while (curr != target) {
            res++;
            if ((curr + res) <= target)
                curr += res;
            else
                curr -= res;
        }
        return res;
    }
};