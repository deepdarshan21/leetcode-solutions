#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Memorization

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(n)
   Status: Accepted
   Runtime: 187 ms faster than: 79%
   Memory Usage: 9.2 MB less than: 54%
   Remarks:
*/

class Solution {
   public:
    int numSquares(int n) {
        vector<int> dp(n + 1, -1);
        return help(n, dp);
    }
    int help(int n, vector<int> &dp) {
        if (n == 0) return dp[0] = 0;
        if (dp[n] != -1) return dp[n];
        int res = INT_MAX;
        for (int i = sqrt(n); i >= 1; i--) {
            // cout<<i<<endl;
            res = min(res, 1 + help(n - i * i, dp));
            // cout<<"res: "<<res<<endl;
        }
        return dp[n] = res;
    }
};