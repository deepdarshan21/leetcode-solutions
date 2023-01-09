#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DFS

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 461 ms faster than: 61%
   Memory Usage: 138.9 MB less than: 34.12%
   Remarks:
*/

class Solution {
   public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> mp;
        auto dfs = [&](auto dfs, int start) {
            int res = 0;
            if (mp.find(start) != mp.end()) return 0;
            for (int i = 0; i < mp[start].size(); i++) {
                res = max(res, dfs(dfs, mp[start][i]));
            }
            res += informTime[start];
            return res;
        };
        for (int i = 0; i < n; i++) {
            if (manager[i] == -1) continue;
            mp[manager[i]].push_back(i);
        }
        return dfs(dfs, headID);
    }
};