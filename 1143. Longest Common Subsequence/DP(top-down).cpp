#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP Bottom Up


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   private:
    int memo[1001][1001] = {-1};

   public:
    int longestCommonSubsequence(string text1, string text2) {
        memset(memo, -1, sizeof(memo));
        return help(text1, text2);
    }
    int help(string text1, string text2) {
        int l1 = text1.size(), l2 = text2.size();
        if (memo[l1][l2] == -1) {
            if (l1 == 0 || l2 == 0) {
                memo[l1][l2] = 0;
            } else if (text1[l1 - 1] == text2[l2 - 1]) {
                memo[l1][l2] = 1 + longestCommonSubsequence(text1.substr(0, l1 - 1), text2.substr(0, l2 - 1));
            } else {
                memo[l1][l2] = max(longestCommonSubsequence(text1.substr(0, l1), text2.substr(0, l2 - 1)), longestCommonSubsequence(text1.substr(0, l1 - 1), text2.substr(0, l2)));
            }
        }
        return memo[l1][l2];
    }
};