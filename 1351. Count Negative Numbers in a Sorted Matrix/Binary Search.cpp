#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search
        Whenever we encounter any number less than zero, simply count zero in that column below that
        element and move toward positive number

   Edge Cases:
        1. When i==row-1
   Time Complexity: O(n+m) Space: O(1)
   Status: Accepted
   Runtime: 15 ms faster than: 86.08%
   Memory Usage: 10.5 MB less than: 47.89%
   Remarks:
*/

class Solution {
   public:
    int countNegatives(vector<vector<int>>& grid) {
        int row = grid.size(), column = grid[0].size();
        int i = 0, j = column - 1;
        int count = 0;
        while (i < row && j >= 0) {
            if (grid[i][j] < 0) {
                count += column - i;
                j--;
            } else {
                if (i < (row - 1) && grid[i + 1][j] < 0) {
                    count += column - i - 1;
                    j--;
                } else {
                    i++;
                }
            }
        }
        return count;
    }
};