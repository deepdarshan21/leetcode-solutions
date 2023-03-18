#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP(bottom up)

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 507 ms faster than: 27.45%
   Memory Usage: 721.7 MB less than: 9.80%
   Remarks:
*/

class Solution {
   public:
    string largestNumber(vector<int>& cost, int target) {
        vector<string> dp(target + 1, "0");

        auto isBigger = [&](string a, string b) -> bool {
            if (a.size() != b.size()) return a.size() > b.size();
            int n = a.size();
            for (int i = 0; i < n; i++) {
                if (a[i] > b[i]) return true;
            }
            return false;
        };

        dp[0] = "";
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < 9; j++) {
                if (i >= cost[j]) {
                    string tmp = "";
                    tmp += (j + 1) + 48;
                    string temp = dp[i - cost[j]];
                    if (temp == "0") continue;
                    tmp += temp;
                    if (isBigger(tmp, dp[i])) dp[i] = tmp;
                }
            }
        }

        return dp[target];
    }
};