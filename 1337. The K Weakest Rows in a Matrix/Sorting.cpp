#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Sorting
        First make a vector pair of and store the row no. and count of soldiers.
        then short them.

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n)
   Status: Accepted
   Runtime: 14 ms faster than: 66.14%
   Memory Usage: 10.14 MB less than: 91.37%
   Remarks:
*/

class Solution {
   public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> store;
        for (int i = 0; i < mat.size(); i++) {
            int count1 = 0;
            while (count1 < mat[i].size()) {
                if (mat[i][count1] == 1) {
                    count1++;
                } else {
                    break;
                }
            }
            store.push_back({count1, i});
        }
        sort(store.begin(), store.end());
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(store[i].second);
        }
        return res;
    }
};