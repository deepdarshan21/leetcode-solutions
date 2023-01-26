#include <bits/stdc++.h>
using namespace std;

/*
   Approach: BFS
        Check all possible paths from src to dst with at most k stops.

   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks: Needed to implement a dynaminc programming to avoid TLE.
*/

class Solution {
   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> gh(n);  // {node, cost}
        for (auto flight : flights) {
            gh[flight[0]].push_back({flight[1], flight[2]});
        }
        queue<vector<int>> q;  // {node, cost, stops}
        q.push({src, 0, 0});
        int res = INT_MAX;
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            if (curr[0] == dst) {
                res = min(res, curr[1]);
            }
            if (curr[2] > k) continue;
            for (auto next : gh[curr[0]]) {
                if (curr[1] + next.second > res) continue;
                q.push({next.first, curr[1] + next.second, curr[2] + 1});
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};