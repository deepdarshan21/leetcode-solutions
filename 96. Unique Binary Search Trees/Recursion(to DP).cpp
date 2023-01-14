#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP

   Edge Cases:

   Time Complexity: O(n) Space: O(logn)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 6 MB less than: 43.67%
   Remarks:
*/

class Solution {
   public:
    int numTrees(int n) {
        vector<int> dp(n, -1);
        auto help = [&](auto help, int low, int high) {
            int diff = abs(low - high);
            if (dp[diff] != -1) return dp[diff];
            if (low >= high) return 1;
            int res = 0;
            for (int i = low; i <= high; i++) {
                int tmp = help(help, low, i - 1) * help(help, i + 1, high);
                // cout<<low<<" "<<i<<" "<<high<<" "<<tmp<<endl;
                res += tmp;
            }
            if (diff == 1) return res;
            return dp[diff] = res;
        };
        return help(help, 1, n);
    }
};