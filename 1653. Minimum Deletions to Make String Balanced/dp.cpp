#include <bits/stdc++.h>
using namespace std;

/*
   Approach: find min deletion for substring(0, i)

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 318 ms faster than: 26.61%
   Memory Usage: 36.8 MB less than: 33.66%
   Remarks:
*/

class Solution {
   public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        int bCount = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a')
                dp[i + 1] = min(dp[i] + 1, bCount);
            else {
                dp[i + 1] = dp[i];
                bCount++;
            }
        }
        return dp[n];
    }
};