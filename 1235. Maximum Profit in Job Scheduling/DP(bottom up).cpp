#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP(bottom up)

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(n)
   Status: Accepted
   Runtime: 177 ms faster than: 56.94%
   Memory Usage: 59.3 MB less than: 49.7%
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

        vector<int> dp(n + 1, -1);

        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            int next = lower_bound(startTime.begin(), startTime.end(), jobs[i][1]) - startTime.begin();
            dp[i] = max(jobs[i][2] + dp[next], dp[i + 1]);
        }

        return dp[0];
    }
};