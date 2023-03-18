#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP bottom up

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n)
   Status: Accepted
   Runtime: 4 ms faster than: 71.2%
   Memory Usage: 9.6 MB less than: 80.71%
   Remarks:
*/

class Solution {
   public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, -1);

        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            int ans = INT_MAX;
            ans = min(ans, costs[0] + dp[i + 1]);
            bool flag;
            flag = true;
            for (int j = i; j < n; j++) {
                if (days[j] >= days[i] + 7) {
                    ans = min(ans, costs[1] + dp[j]);
                    flag = false;
                    break;
                }
            }
            if (flag) ans = min(ans, costs[1] + dp[n]);
            flag = true;
            for (int j = i; j < n; j++) {
                if (days[j] >= days[i] + 30) {
                    ans = min(ans, costs[2] + dp[j]);
                    flag = false;
                    break;
                }
            }
            if (flag) ans = min(ans, costs[2] + dp[n]);
            dp[i] = ans;
        }

        return dp[0];
    }
};