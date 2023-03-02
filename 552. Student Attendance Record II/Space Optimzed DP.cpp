#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Space Optimization on DP(bottom up)

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 384 ms faster than: 54.6%
   Memory Usage: 6 MB less than: 95.61%
   Remarks:
*/

class Solution {
   public:
    int checkRecord(int n) {
        int mod = 1e9 + 7;
        vector<vector<int>> prev(2, vector<int>(3, -1));
        vector<vector<int>> curr(2, vector<int>(3, -1));

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                prev[i][j] = 1;
            }
        }

        for (int numDays = 1; numDays <= n; numDays++) {
            for (int numAbsent = 0; numAbsent < 2; numAbsent++) {
                for (int numLate = 0; numLate < 3; numLate++) {
                    int res = 0;
                    if (numAbsent > 0) res = (res + prev[numAbsent - 1][2]) % mod;
                    if (numLate > 0) res = (res + prev[numAbsent][numLate - 1]) % mod;
                    res = (res + prev[numAbsent][2]) % mod;
                    curr[numAbsent][numLate] = res;
                }
            }
            prev = curr;
        }

        return prev[1][2];
    }
};