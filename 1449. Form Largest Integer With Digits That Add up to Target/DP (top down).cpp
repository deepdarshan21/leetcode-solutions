#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP (top down)

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 540 ms faster than: 27.45%
   Memory Usage: 722.4 MB less than: 7.84%
   Remarks:
*/

class Solution {
   public:
    string largestNumber(vector<int>& cost, int target) {
        vector<string> dp(target + 1, "-1");

        auto rec = [&](auto self, int t) -> string {
            if (t == 0) return "";
            if (dp[t] != "-1") return dp[t];
            string ans = "0";

            auto isBigger = [&](string a, string b) -> bool {
                if (a.size() != b.size()) return a.size() > b.size();
                int n = a.size();
                for (int i = 0; i < n; i++) {
                    if (a[i] > b[i]) return true;
                }
                return false;
            };

            for (int i = 0; i < 9; i++) {
                if (t >= cost[i]) {
                    string tmp = "";
                    tmp += (i + 1) + 48;
                    string temp = self(self, t - cost[i]);
                    if (temp == "0") continue;
                    tmp += temp;
                    // cout<<tmp<<endl;
                    if (isBigger(tmp, ans)) ans = tmp;
                }
            }
            return dp[t] = ans;
        };
        return rec(rec, target);
    }
};