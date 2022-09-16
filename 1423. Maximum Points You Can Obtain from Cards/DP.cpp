#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        memo.resize(n, vector<int>(n, -1));
        return dp(cardPoints, k, 0, n - 1);
    }

   private:
    vector<vector<int>> memo;
    int dp(vector<int>& cardPoint, int k, int low, int high) {
        if (k == 0) return 0;
        if (memo[low][high] != -1) return memo[low][high];
        int left, right;
        left = cardPoint[low] + dp(cardPoint, k - 1, low + 1, high);
        right = cardPoint[high] + dp(cardPoint, k - 1, low, high - 1);
        memo[low][high] = max(left, right);
        return memo[low][high];
    }
};