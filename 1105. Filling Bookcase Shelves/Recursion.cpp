#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Recursion

   Edge Cases:

   Time Complexity: O(n^n) Space: O(n)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        auto rec = [&](auto self, int idx) -> int {
            if (idx == n) return 0;
            int width = 0, height = 0, ans = INT_MAX;
            for (int i = idx; i < n; i++) {
                width += books[i][0];
                if (width > shelfWidth) break;
                height = max(height, books[i][1]);
                ans = min(ans, height + self(self, i + 1));
            }
            return ans;
        };
        return rec(rec, 0);
    }
};