#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP(bottom up)
        We know that if n is even, then Alice can always win by choosing 1.
        If n is odd, then Alice will lose, because she can only choose odd numbers, and Bob will always choose even numbers.
        So we can use a dp array to store the result of each number.
        If n is even, then dp[n] = true, otherwise dp[n] = false.
        Then we can use a for loop to iterate from 3 to n, and for each number, we can use a for loop to iterate from 1 to n/2, and check if n % i == 0 and dp[n - i] == false, if so, dp[n] = true, and break the loop.
        Finally, we can return dp[n].

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n)
   Status: Accepted
   Runtime: 2 ms faster than: 51%
   Memory Usage: 6 MB less than: 17.99%
   Remarks:
*/

class Solution {
   public:
    bool divisorGame(int n) {
        if (n == 1) return false;
        if (n == 2) return true;
        vector<bool> dp(n + 1, false);
        dp[2] = true;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j <= i / 2; j++) {
                if (i % j == 0 && !dp[i - j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};