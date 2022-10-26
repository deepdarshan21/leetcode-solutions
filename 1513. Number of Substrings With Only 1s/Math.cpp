#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Math

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 26 ms faster than: 43.12%
   Memory Usage: 8.7 MB less than: 72.29%
   Remarks:
*/

class Solution {
   public:
    int numSub(string s) {
        int res = 0, n = s.size(), mod = 1e9 + 7;
        int temp = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                res = (res + (i - temp)) % mod;
            else
                temp = i;
        }
        return res;
    }
};