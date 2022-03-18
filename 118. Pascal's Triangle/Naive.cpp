#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force


   Edge Cases:

   Time Complexity: O(n^2) Space: O(n^2)
   Status: Accepted
   Runtime: 3 ms faster than: 30.47%
   Memory Usage: 6.4 MB less than: 71.88%
   Remarks:
*/

class Solution {
   public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        res[0] = {1};
        for (int i = 1; i < numRows; i++) {
            vector<int> temp(i + 1);
            res[i] = temp;
            for (int j = 0; j < i + 1; j++) {
                if (j == 0 || j == i) {
                    res[i][j] = 1;
                } else {
                    res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
                }
            }
        }
        return res;
    }
};