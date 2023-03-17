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
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();

        auto rec = [&](auto self, int idx, int canBeUsed) -> int {
            if (idx == n) return 0;
            int ans = INT_MAX;
            if (canBeUsed >= days[idx]) {
                ans = min(ans, self(self, idx + 1, canBeUsed));
            } else {
                ans = min(ans, costs[0] + self(self, idx + 1, days[idx]));
                ans = min(ans, costs[1] + self(self, idx + 1, days[idx] + 6));
                ans = min(ans, costs[2] + self(self, idx + 1, days[idx] + 29));
            }
            return ans;
        };

        return rec(rec, 0, 0);
    }
};