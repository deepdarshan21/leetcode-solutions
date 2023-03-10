#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int countTriplets(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        vector<vector<int>> dp(1000000, vector<int>(3, -1));
        auto rec = [&](auto self, int currAND, int count) -> int {
            if (currAND == 0) {
                if (count == 0) return 1;
                if (count == 1) return n;
                if (count == 2) return n * n;
            }
            if (count == 0) return 0;
            if (dp[currAND][count] != -1) return dp[currAND][count];
            int res = 0;
            for (int i = 0; i < n; i++) res += self(self, currAND & nums[i], count - 1);
            return dp[currAND][count] = res;
        };
        for (int i = 0; i < n; i++) {
            res += rec(rec, nums[i], 2);
        }
        return res;
    }
};