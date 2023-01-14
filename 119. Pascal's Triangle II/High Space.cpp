#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O(n) Space: O(n*n)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 6.7 MB less than: 16.62%
   Remarks:
*/

class Solution {
   public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return {1};
        if (rowIndex == 1) return {1, 1};
        vector<vector<int>> rows(rowIndex + 1);
        rows[0] = {1};
        rows[1] = {1, 1};
        for (int i = 2; i <= rowIndex; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    rows[i].push_back(1);
                    continue;
                }
                rows[i].push_back(rows[i - 1][j] + rows[i - 1][j - 1]);
            }
        }
        return rows[rowIndex];
    }
};