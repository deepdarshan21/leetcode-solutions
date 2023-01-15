#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DSU

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 875 ms faster than: 65.15%
   Memory Usage: 244.7 MB less than: 16.29%
   Remarks:
*/

class Solution {
   public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<int> par(n), rank(n, 0);
        vector<vector<int>> gh(n);
        map<int, vector<int>> valsToNode;
        int res = n;
        auto findPar = [&](auto findPar, int node) {
            if (par[node] == node) return node;
            return par[node] = findPar(findPar, par[node]);
        };
        auto unionN1AndN2 = [&](int n1, int n2) {
            int par1 = findPar(findPar, n1);
            int par2 = findPar(findPar, n2);
            if (par1 == par2)
                return;
            else if (rank[par1] > rank[par2])
                par[par2] = par1;
            else if (rank[par1] < rank[par2])
                par[par1] = par2;
            else {
                par[par1] = par2;
                rank[par2]++;
            }
        };
        for (int i = 0; i < n; i++) par[i] = i;
        for (auto edge : edges) {
            gh[edge[0]].push_back(edge[1]);
            gh[edge[1]].push_back(edge[0]);
        }
        for (int i = 0; i < n; i++) valsToNode[vals[i]].push_back(i);

        for (auto [value, nodes] : valsToNode) {
            for (auto node : nodes) {
                for (auto neighboor : gh[node]) {
                    if (vals[node] >= vals[neighboor]) {
                        unionN1AndN2(node, neighboor);
                    }
                }
            }
            unordered_map<int, int> count;
            for (auto node : nodes) count[findPar(findPar, node)]++;
            for (auto [_, n] : count) {
                res += n * (n - 1) / 2;
            }
        }
        return res;
    }
};