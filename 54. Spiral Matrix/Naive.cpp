#include <bits/stdc++.h>
using namespace std;

/*
   Approach: naive


   Edge Cases:

   Time Complexity: O(m*n) Space: O(1)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 6.8 MB less than: 73.48%
   Remarks:
*/

class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int top, down, left, right;
        top = 0;
        down = n - 1;
        left = 0;
        right = m - 1;
        int dir = 0;
        vector<int> res;

        while (top <= down && left <= right) {
            if (dir == 0) {
                for (int i = left; i <= right; i++) {
                    res.push_back(matrix[top][i]);
                }
                top++;
            } else if (dir == 1) {
                for (int i = top; i <= down; i++) {
                    res.push_back(matrix[i][right]);
                }
                right--;
            } else if (dir == 2) {
                for (int i = right; i >= left; i--) {
                    res.push_back(matrix[down][i]);
                }
                down--;
            } else if (dir == 3) {
                for (int i = down; i >= top; i--) {
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
            dir = (dir + 1) % 4;
        }
        return res;
    }
};