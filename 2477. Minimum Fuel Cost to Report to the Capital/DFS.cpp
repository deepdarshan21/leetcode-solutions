#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DFS
        First we need to find the height of each node in the tree.
        Then we need to find the number of seats required for each node.
        Then we need to find the fuel required for each node.
        Then we need to find the total fuel required.

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status:
   Runtime: 702 ms faster than: 49.74%
   Memory Usage: 234.8 MB less than: 13.18%
   Remarks:
*/

class Solution {
   public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        unordered_map<int, vector<int>> gh;
        for (int i = 0; i < n; i++) {
            gh[roads[i][0]].push_back(roads[i][1]);
            gh[roads[i][1]].push_back(roads[i][0]);
        }
        vector<int> heightVisted(n + 1, 0);

        auto dfs = [&](auto dfs, int node) -> int {
            if (heightVisted[node] != 0) return 0;
            heightVisted[node] = 1;
            for (auto child : gh[node]) {
                heightVisted[node] += dfs(dfs, child);
            }
            return heightVisted[node];
        };

        dfs(dfs, 0);

        long long fuelRequired = 0LL;
        for (int i = 1; i < n + 1; i++) {
            fuelRequired += ceil(heightVisted[i] / (seats * 1.0));
        }
        return fuelRequired;
    }
};