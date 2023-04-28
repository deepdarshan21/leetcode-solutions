#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DSU


   Edge Cases:

   Time Complexity: O(n^3) Space: O(n)
   Status:
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
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
                rank[v] = u;
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
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        DSU tmpDSU(n);
        unordered_map<string, int> store;
        int i = 0;
        for (string str : strs) store[str] = i++;
        for (int i = 0; i < n; i++) {
            string str = strs[i];
            int m = str.size();
            for (int j = 0; j < m; j++) {
                for (int k = j + 1; k < m; k++) {
                    swap(str[j], str[k]);
                    if (store.count(str)) tmpDSU.unionNode(store[str], i);
                    swap(str[j], str[k]);
                }
            }
        }
        return tmpDSU.distGrp();
    }
};