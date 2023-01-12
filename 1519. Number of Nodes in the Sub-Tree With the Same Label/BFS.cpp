#include <bits/stdc++.h>
using namespace std;

/*
   Approach: BFS

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 684 ms faster than: 74.8%
   Memory Usage: 190 MB less than: 75.86%
   Remarks:
*/

class Solution {
   public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> gh(n);
        vector<int> res(n, 0);
        for (vector<int> edge : edges) {
            gh[edge[0]].push_back(edge[1]);
            gh[edge[1]].push_back(edge[0]);
        }
        vector<vector<int>> temp(n, vector<int>(26, 0));
        queue<int> q;
        for (int i = 0; i < n; i++) {
            temp[i][labels[i] - 97] = 1;
            if (i != 0 and gh[i].size() == 1) q.push(i);
        }
        while (!q.empty()) {
            int tmp = q.front();
            q.pop();
            int parent = gh[tmp][0];
            gh[parent].erase(find(gh[parent].begin(), gh[parent].end(), tmp));
            for (int i = 0; i < 26; i++) temp[parent][i] += temp[tmp][i];
            if (parent != 0 and gh[parent].size() == 1) {
                q.push(parent);
            }
        }
        for (int i = 0; i < n; i++) {
            res[i] = temp[i][labels[i] - 97];
        }
        return res;
    }
};