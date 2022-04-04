#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search on Matrix


   Edge Cases:

   Time Complexity: O(m+n) Space: O(1)
   Status: Accepted
   Runtime: 10 ms faster than: 18.85%
   Memory Usage: 9.7 MB less than: 5.82%
   Remarks:
*/

class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0, j = matrix[0].size() - 1;
        while (i < matrix.size() && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            } else {
                if (matrix[i][j] < target) {
                    i++;
                } else {
                    j--;
                }
            }
        }
        return false;
    }
};