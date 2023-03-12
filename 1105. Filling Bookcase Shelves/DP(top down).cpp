#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP(top down)

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 3 ms faster than: 95%
   Memory Usage: 8.5 MB less than: 45.30%
   Remarks:
*/

class Solution {
   public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n, -1);
        auto rec = [&](auto self, int idx) -> int {
            if (idx == n) return 0;
            if (dp[idx] != -1) return dp[idx];
            int width = 0, height = 0, ans = INT_MAX;
            for (int i = idx; i < n; i++) {
                width += books[i][0];
                if (width > shelfWidth) break;
                height = max(height, books[i][1]);
                ans = min(ans, height + self(self, i + 1));
            }
            return dp[idx] = ans;
        };
        return rec(rec, 0);
    }
};