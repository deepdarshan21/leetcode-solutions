#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP + BFS
        Not move to the next node if the cost is greater than the current cost

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 60 ms faster than: 24.80%
   Memory Usage: 13.9 MB less than: 28.58%
   Remarks:
*/

class Solution {
   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> gh(n);  // {node, cost}
        for (auto flight : flights) {
            gh[flight[0]].push_back({flight[1], flight[2]});
        }
        vector<int> dp(n, INT_MAX);
        queue<vector<int>> q;  // {node, cost, stops}
        q.push({src, 0, 0});
        dp[src] = 0;
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            if (curr[0] == dst) {
                continue;
            }
            if (curr[2] > k) continue;
            for (auto next : gh[curr[0]]) {
                if (curr[1] + next.second >= dp[next.first]) continue;
                dp[next.first] = curr[1] + next.second;
                q.push({next.first, curr[1] + next.second, curr[2] + 1});
            }
        }
        return dp[dst] == INT_MAX ? -1 : dp[dst];
    }
};