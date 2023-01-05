#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Without extra space

   Edge Cases:

   Time Complexity: O(2*m*n) Space: O(1)
   Status: Accepted
   Runtime: 35 ms faster than: 24%
   Memory Usage: 13.2 MB less than: 60%
   Remarks:
*/

class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};