#include <bits/stdc++.h>
using namespace std;

/*
   Approach:Tebulation

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 129 ms faster than: 5.08%
   Memory Usage: 6.2 MB less than: 8.17%
   Remarks:
*/

class Solution {
   public:
    vector<int> dp;
    int fib(int n) {
        dp.resize(n + 1, -1);
        dp[0] = 0;
        dp[1] = 1;
        return fib(n, dp);
    }
    int fib(int n, vector<int> &dp) {
        if (dp[n] != -1) return dp[n];
        dp[n] = fib(n - 1) + fib(n - 2);
        return dp[n];
    }
};