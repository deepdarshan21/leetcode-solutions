#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Recursion(backtracking)

   Edge Cases:

   Time Complexity: O(n^2) Space: O(logn)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<vector<int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        sort(startTime.begin(), startTime.end());

        auto rec = [&](auto self, int start) -> int {
            auto it = lower_bound(startTime.begin(), startTime.end(), start);
            if (it == startTime.end()) return 0;
            int i = it - startTime.begin();
            int ans = 0;
            for (int j = i; j < n; j++) {
                ans = max(ans, jobs[j][2] + self(self, jobs[j][1]));
            }
            return ans;
        };

        return rec(rec, 0);
    }
};