#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 29 ms faster than: 72.66%
   Memory Usage: 11.1 MB less than: 52.66%
   Remarks:
*/

class Solution {
   public:
    int minFlipsMonoIncr(string s) {
        int res = 0, ones = 0;
        for (char c : s) {
            if (c == '0')
                res = min(ones, res + 1);
            else
                ones++;
        }
        return res;
    }
};