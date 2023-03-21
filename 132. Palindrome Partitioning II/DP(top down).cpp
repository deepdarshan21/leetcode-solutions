#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP(top down)

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n)
   Status: Accepted
   Runtime: 473 ms faster than: 34.43%
   Memory Usage: 6.4 MB less than: 97.68%
   Remarks:
*/

class Solution {
   public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, -1);

        function<bool(int, int)> isPalindrome = [&](int l, int h) -> bool {
            while (l <= h) {
                if (s[l] != s[h]) return false;
                l++;
                h--;
            }
            return true;
        };

        dp[n] = 0;

        for (int l = n - 1; l >= 0; l--) {
            if (isPalindrome(l, n - 1))
                dp[l] = 0;
            else {
                int res = INT_MAX;
                for (int i = l + 1; i < n; i++) {
                    if (isPalindrome(l, i - 1)) res = min(res, 1 + dp[i]);
                }
                dp[l] = res;
            }
        }

        return dp[0];
    }
};