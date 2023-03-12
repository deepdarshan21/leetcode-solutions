#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP(bottom up)

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n)
   Status: Accepted
   Runtime: 5 ms faster than: 79%
   Memory Usage: 8.1 MB less than: 81.22%
   Remarks:
*/

class Solution {
   public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, -1);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            int width = 0, height = 0, ans = INT_MAX;
            for (int j = i; j < n; j++) {
                width += books[j][0];
                if (width > shelfWidth) break;
                height = max(height, books[j][1]);
                ans = min(ans, height + dp[j + 1]);
            }
            dp[i] = ans;
        }
        return dp[0];
    }
};