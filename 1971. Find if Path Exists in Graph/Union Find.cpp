#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Union Find

   Edge Cases:

   Time Complexity: O(len(edges)) Space: O(n)
   Status: Accepted
   Runtime: 518 ms faster than: 94.52%
   Memory Usage: 135 MB less than: 87.27%
   Remarks:
*/

class Solution {
   public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        int sou = source;
        int des = destination;
        vector<int> par(n), rank(n, 0);
        for (int i = 0; i < n; i++) par[i] = i;
        auto findPar = [&](auto findPar, int node) {
            if (node == par[node]) return node;
            return par[node] = findPar(findPar, par[node]);
        };
        auto unionN1AndN2 = [&](int n1, int n2) {
            int parN1 = findPar(findPar, n1);
            int parN2 = findPar(findPar, n2);
            if (rank[parN1] == rank[parN2]) {
                par[parN2] = parN1;
                rank[parN1]++;
            } else {
                if (rank[parN1] > rank[parN2]) {
                    par[parN2] = parN1;
                } else {
                    par[parN1] = parN2;
                }
            }
        };
        for (vector<int> edge : edges) unionN1AndN2(edge[0], edge[1]);
        if (findPar(findPar, sou) == findPar(findPar, des)) return true;
        return false;
    }
};