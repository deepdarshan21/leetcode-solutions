#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search on matrix

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 178 ms faster than: 36.13%
   Memory Usage: 14.8 MB less than: 69.13%
   Remarks:
*/

class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0, j = matrix[0].size() - 1;
        while (i < matrix.size() && j >= 0) {
            if (target == matrix[i][j]) {
                return true;
            } else {
                if (target > matrix[i][j]) {
                    i++;
                } else {
                    j--;
                }
            }
        }
        return false;
    }
};