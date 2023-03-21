#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP(bottom up)

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n)
   Status: Accepted
   Runtime: 469 ms faster than: 35.13%
   Memory Usage: 7.5 MB less than: 52.95%
   Remarks:
*/

class Solution {
   public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, -1);

        function<int(int)> help = [&](int l) -> int {
            function<bool(int, int)> isPalindrome = [&](int l, int h) -> bool {
                while (l <= h) {
                    if (s[l] != s[h]) return false;
                    l++;
                    h--;
                }
                return true;
            };
            if (dp[l] != -1) return dp[l];

            if (isPalindrome(l, n - 1)) return dp[l] = 0;
            int res = INT_MAX;
            for (int i = l + 1; i < n; i++) {
                if (isPalindrome(l, i - 1)) res = min(res, 1 + help(i));
            }
            return dp[l] = res;
        };

        return help(0);
    }
};