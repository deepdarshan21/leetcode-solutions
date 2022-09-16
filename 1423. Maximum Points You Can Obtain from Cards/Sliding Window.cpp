#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Sliding Window


   Edge Cases:

   Time Complexity: O(k) Space: O(1)
   Status: Accepted
   Runtime: 139 ms faster than: 17.69%
   Memory Usage: 42.4 MB less than: 46.56%
   Remarks:
*/

class Solution {
   public:
    int maxScore(vector<int>& cardPoints, int k) {
        int score, maxScore, n = cardPoints.size();
        maxScore = score = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0);
        for (int i = 0; i < k; i++) {
            score += cardPoints[n - 1 - i] - cardPoints[k - 1 - i];
            maxScore = max(score, maxScore);
        }
        return maxScore;
    }
};