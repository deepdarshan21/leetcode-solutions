#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 9 ms faster than: 23.31%
   Memory Usage: 9.9 MB less than: 24.60%
   Remarks:
*/

class Solution {
   public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, -1);

        auto rec = [&](auto self, int idx) -> int {
            if (idx == n) return 0;
            if (dp[idx] != -1) return dp[idx];
            int ans = INT_MAX;
            ans = min(ans, costs[0] + self(self, idx + 1));
            bool flag;
            flag = true;
            for (int i = idx; i < n; i++) {
                if (days[i] >= days[idx] + 7) {
                    ans = min(ans, costs[1] + self(self, i));
                    flag = false;
                    break;
                }
            }
            if (flag) ans = min(ans, costs[1] + self(self, n));
            flag = true;
            for (int i = idx; i < n; i++) {
                if (days[i] >= days[idx] + 30) {
                    ans = min(ans, costs[2] + self(self, i));
                    flag = false;
                    break;
                }
            }
            if (flag) ans = min(ans, costs[2] + self(self, n));
            return dp[idx] = ans;
        };

        return rec(rec, 0);
    }
};