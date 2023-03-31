#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Recursive(Prefix Sum)

   Edge Cases:

   Time Complexity: O(2^(n*m*k*(m+n))) Space: O(m*n*k*(m+n))
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int ways(vector<string>& pizza, int k) {
        int n = pizza.size(), m = pizza[0].size();
        int mod = 1e9 + 7;
        vector<vector<int>> preSum(n + 1, vector<int>(m + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                preSum[i][j] = preSum[i + 1][j] + preSum[i][j + 1] - preSum[i + 1][j + 1] + (pizza[i][j] == 'A' ? 1 : 0);
            }
        }

        function<int(int, int, int)> rec = [&](int idx, int jdx, int c) -> int {
            if (preSum[idx][jdx] == 0) return 0;
            if (c == 0) return 1;
            int res = 0;
            for (int i = idx + 1; i < n; i++) {
                if (preSum[idx][jdx] - preSum[i][jdx] > 0) {
                    res = (res + rec(i, jdx, c - 1)) % mod;
                }
            }
            for (int j = jdx + 1; j < m; j++) {
                if (preSum[idx][jdx] - preSum[idx][j] > 0) {
                    res = (res + rec(idx, j, c - 1)) % mod;
                }
            }
            cout << idx << " " << jdx << " " << c << " " << res << endl;
            return res;
        };
        return rec(0, 0, k - 1);
    }
};