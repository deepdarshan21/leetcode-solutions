#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force
        Poure the available champange in that glass and then check if there is any overflow then
        remove the overflowable champagne into glasses below to it equally.

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n)
   Status: Accepted
   Runtime: 23 ms faster than: 37.90%
   Memory Usage: 18.1 MB less than: 31.90%
   Remarks:
*/

class Solution {
   public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> tower(query_row + 1);
        for (int i = 0; i <= query_row; i++) {
            for (int j = 0; j <= i; j++) {
                tower[i].push_back(0.0);
            }
        }
        tower[0][0] = poured;
        double overflow;
        for (int i = 0; i < query_row; i++) {
            for (int j = 0; j <= i; j++) {
                overflow = (tower[i][j] - 1.0) / 2.0;
                if (overflow > 0) {
                    tower[i + 1][j] += overflow;
                    tower[i + 1][j + 1] += overflow;
                }
            }
        }
        if (tower[query_row][query_glass] < 1) {
            return tower[query_row][query_glass];
        }
        return 1.0;
    }
};