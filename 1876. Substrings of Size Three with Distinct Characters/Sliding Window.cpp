#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Sliding Window

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 6.1 MB less than: 75.58%
   Remarks:
*/

class Solution {
   public:
    int countGoodSubstrings(string s) {
        int res = 0, n = s.size();
        for (int i = 2; i < n; i++) {
            if (s[i] != s[i - 1] && s[i] != s[i - 2] && s[i - 1] != s[i - 2]) res++;
        }
        return res;
    }
};