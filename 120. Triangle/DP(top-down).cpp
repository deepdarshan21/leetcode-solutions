#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP(Top-down)

   Edge Cases:

   Time Complexity: O(n*n) Space: O(1)
   Status: Accepted
   Runtime: 6 ms faster than: 80.67%
   Memory Usage: 8.6 MB less than: 78.90%
   Remarks:
*/

class Solution {
   public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for (int i = (n - 2); i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];
    }
};