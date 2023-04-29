#include <bits/stdc++.h>
using namespace std;

/*
   Approach: First sorting and then DSU for grouping

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(n)
   Status: Accepted
   Runtime: 665 ms faster than: 39.84%
   Memory Usage: 116.2 MB less than: 31.54%
   Remarks:
*/

class Solution {
   private:
    class DSU {
       private:
        vector<int> par, rank;

       public:
        DSU(int n) {
            par.resize(n);
            rank.resize(n);
            for (int i = 0; i < n; i++) {
                par[i] = i;
                rank[i] = 0;
            }
        }
        int findPar(int node) {
            if (node == par[node]) return node;
            return par[node] = findPar(par[node]);
        }
        void unionNode(int u, int v) {
            u = findPar(u);
            v = findPar(v);
            if (rank[u] > rank[v])
                par[v] = u;
            else if (rank[u] < rank[v])
                par[u] = v;
            else {
                par[v] = u;
                rank[u]++;
            }
        }
        int distGrp() {
            unordered_map<int, int> mp;
            for (int itr : par) mp[itr]++;
            return mp.size();
        }
    };

   public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        DSU dsu(n);
        unordered_map<int, vector<pair<int, int>>> gh;
        int u, v, dist;
        for (int i = 0; i < queries.size(); i++) queries[i].push_back(i);
        sort(edgeList.begin(), edgeList.end(), [](vector<int>& e1, vector<int>& e2) { return e1[2] < e2[2]; });
        sort(queries.begin(), queries.end(), [](vector<int>& tmp1, vector<int>& tmp2) { return tmp1[2] < tmp2[2]; });
        vector<bool> res(queries.size());
        int i = 0, m = edgeList.size();
        for (auto itr : queries) {
            while (i < m && edgeList[i][2] < itr[2]) dsu.unionNode(edgeList[i][0], edgeList[i][1]);
            if (dsu.findPar(itr[0]) == dsu.findPar(itr[1]))
                res[itr[3]] = true;
            else
                res[itr[3]] = false;
        }
        return res;
    }
};