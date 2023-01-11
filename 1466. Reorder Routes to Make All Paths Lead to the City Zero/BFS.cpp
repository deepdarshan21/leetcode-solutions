#include <bits/stdc++.h>
using namespace std;

/*
   Approach: BFS

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 510 ms faster than: 72.59%
   Memory Usage: 124.3 MB less than: 43.8%
   Remarks:
*/

class Solution {
   public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<bool> vis(n, false);
        vector<vector<int>> gh(n), ghMain(n);
        for (vector<int> con : connections) {
            gh[con[0]].push_back(con[1]);
            gh[con[1]].push_back(con[0]);
            ghMain[con[0]].push_back(con[1]);
        }
        int res = 0;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int tmp = q.front();
            q.pop();
            vis[tmp] = true;
            for (int itr : gh[tmp]) {
                if (!vis[itr]) {
                    q.push(itr);
                    if (find(ghMain[tmp].begin(), ghMain[tmp].end(), itr) != ghMain[tmp].end()) res++;
                }
            }
        }
        return res;
    }
};