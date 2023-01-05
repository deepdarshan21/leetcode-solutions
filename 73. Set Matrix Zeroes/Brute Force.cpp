#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Using set
        First store the elements in a set then check if that index is in set the set that ekement to 0

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 36 ms faster than: 20%
   Memory Usage: 13.5 MB less than: 12%
   Remarks:
*/

class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> row, col;
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (row.find(i) != row.end()) {
                    matrix[i][j] = 0;
                } else if (col.find(j) != col.end()) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};