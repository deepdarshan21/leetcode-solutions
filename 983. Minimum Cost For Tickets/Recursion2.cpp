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

        auto rec = [&](auto self, int idx) -> int {
            if (idx == n) return 0;
            int ans = INT_MAX;
            ans = min(ans, costs[0] + self(self, idx + 1));
            for (int i = idx; i < n; i++) {
                if (days[i] >= days[idx] + 7) {
                    ans = min(ans, costs[1] + self(self, i));
                    break;
                }
            }
            for (int i = idx; i < n; i++) {
                if (days[i] >= days[idx] + 30) {
                    ans = min(ans, costs[2] + self(self, i));
                    break;
                }
            }
            return ans;
        };

        return rec(rec, 0);
    }
};