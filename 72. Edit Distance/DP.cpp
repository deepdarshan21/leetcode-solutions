#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP

   Edge Cases:

   Time Complexity: O(n1*n2) Space: O(n1*n2)
   Status: Accepted
   Runtime: 18 ms faster than: 57.73%
   Memory Usage: 9.3 MB less than: 19.16%
   Remarks:
*/

class Solution {
   public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        auto help = [&](auto help, int i, int j) {
            if (i == n1) return n2 - j;
            if (j == n2) return n1 - i;
            if (dp[i][j] != -1) return dp[i][j];
            if (word1[i] == word2[j]) return dp[i][j] = help(help, i + 1, j + 1);
            int add = help(help, i, j + 1);
            int replace = help(help, i + 1, j + 1);
            int remove = help(help, i + 1, j);
            return dp[i][j] = min({add, replace, remove}) + 1;
        };
        return help(help, 0, 0);
    }
};