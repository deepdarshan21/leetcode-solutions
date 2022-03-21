#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Math


   Edge Cases:

   Time Complexity: O(n^2) Space: O(1)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 7.1 MB less than: 33.81%
   Remarks:
*/

class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size();
        // transpose
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len / 2; j++) {
                swap(matrix[i][j], matrix[i][len - 1 - j]);
            }
        }
    }
};