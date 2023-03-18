#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP(top down)
        For each job, we can either take it or not take it.
        If we take it, we can only take jobs that start after it ends.
        If we don't take it, we can take any job.
        We can use recursion to solve this problem.
        We can also use memoization to speed up the recursion.

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(n)
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

        vector<int> dp(n, -1);

        auto rec = [&](auto self, int startIdx) -> int {
            if (startIdx == n) return 0;
            if (dp[startIdx] != -1) return dp[startIdx];
            int ans = 0;
            for (int i = startIdx; i < n; i++) {
                int next = lower_bound(startTime.begin(), startTime.end(), jobs[i][1]) - startTime.begin();
                ans = max(ans, jobs[i][2] + self(self, next));
            }
            return dp[startIdx] = ans;
        };

        return rec(rec, 0);
    }
};