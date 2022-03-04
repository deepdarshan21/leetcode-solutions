#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n^2)
   Status: Accpeted
   Runtime: 13 ms faster than: 58.12%
   Memory Usage: 11 MB less than: 35.50%
   Remarks:
*/

class Solution {
   public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if ((mat.size() * mat[0].size()) != (r * c)) {
            return mat;
        }
        vector<vector<int>> res(r);
        int CCount = 0, RCount = 0;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                res[RCount].push_back(mat[i][j]);
                CCount++;
                if (CCount == c) {
                    CCount = 0;
                    RCount++;
                }
            }
        }
        return res;
    }
};