#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Bit manipulation

   Edge Cases:

   Time Complexity: O(1) Space: O(1)
   Status: Accepted
   Runtime: 3 ms faster than: 42.83%
   Memory Usage: 5.9 MB less than: 40.72%
   Remarks:
*/

class Solution {
   public:
    int binaryGap(int n) {
        int res = 0, temp = 0;
        bool start = false;
        while (n != 0) {
            if ((n & 1) == 1) {
                start = true;
                res = max(res, temp);
                temp = 1;
            } else if (start && (n & 1) == 0) {
                temp++;
            }
            n = n >> 1;
        }
        return res;
    }
};