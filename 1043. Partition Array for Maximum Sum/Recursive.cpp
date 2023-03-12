#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Recursion

   Edge Cases:

   Time Complexity: O(k^n) Space: O(n)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        auto rec = [&](auto self, int idx) -> int {
            if (idx == n) return 0;
            int ans = 0, mx = 0;
            for (int i = idx; i < min(idx + k, n); i++) {
                mx = max(mx, arr[i]);
                ans = max(ans, mx * (i - idx + 1) + self(self, i + 1));
            }
            return ans;
        };
        return rec(rec, 0);
    }
};