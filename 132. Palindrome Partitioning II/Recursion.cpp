#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Recursion


   Edge Cases:

   Time Complexity: O(n^3) Space: O(n)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int minCut(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        if (s == rev) return 0;
        int res = 0, n = s.size();
        for (int i = 1; i < n; i++) {
            res = min(res, 1 + minCut(s.substr(0, i)) + minCut(s.substr(i, n)));
        }
        return res;
    }
};