#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DFS using lamda function

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 14 ms faster than: 87.12%
   Memory Usage: 10.7 MB less than: 83.12%
   Remarks:
*/

class Solution {
   public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> res;
        vector<int> visited;
        auto dfs = [&](auto&& dfs) {
            int currNode = visited.back();
            if (currNode == (n - 1)) {
                res.push_back(visited);
                return;
            }
            for (int i = 0; i < graph[currNode].size(); i++) {
                if (find(visited.begin(), visited.end(), graph[currNode][i]) != visited.end()) {
                    continue;
                }
                visited.push_back(graph[currNode][i]);
                dfs(dfs);
                visited.pop_back();
            }
        };
        visited.push_back(0);
        dfs(dfs);
        return res;
    }
};