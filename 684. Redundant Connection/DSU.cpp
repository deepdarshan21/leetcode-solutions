#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DSU

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 13 ms faster than: 51.22%
   Memory Usage: 9.1 MB less than: 49.11%
   Remarks:
*/

class Solution {
   public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> par(n + 1), rank(n + 1, 0);
        auto findPar = [&](auto findPar, int node) {
            if (par[node] == node) return node;
            return par[node] = findPar(findPar, par[node]);
        };
        auto uniteN1AndN2 = [&](int n1, int n2) {
            int parN1 = findPar(findPar, n1);
            int parN2 = findPar(findPar, n2);
            if (rank[parN1] < rank[parN2])
                par[parN1] = parN2;
            else if (rank[parN1] > rank[parN2])
                par[parN2] = parN1;
            else {
                par[parN2] = parN1;
                rank[parN1]++;
            }
        };
        for (int i = 0; i <= n; i++) par[i] = i;
        auto isSame = [&](int n1, int n2) {
            return findPar(findPar, n1) == findPar(findPar, n2);
        };
        for (auto edge : edges) {
            if (isSame(edge[0], edge[1])) return edge;
            uniteN1AndN2(edge[0], edge[1]);
        }
        return {-1, -1};
    }
};