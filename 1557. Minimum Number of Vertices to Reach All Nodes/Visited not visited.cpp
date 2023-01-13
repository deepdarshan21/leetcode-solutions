#include <bits/stdc++.h>
using namespace std;

/*
   Approach: From every node which has no incoming nodes then it will be in ans;

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 375 ms faster than: 76.2%
   Memory Usage: 105.9 MB less than: 55.06%
   Remarks:
*/

class Solution {
   public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, false);
        for (vector<int> itr : edges) vis[itr[1]] = true;
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) res.push_back(i);
        }
        return res;
    }
};