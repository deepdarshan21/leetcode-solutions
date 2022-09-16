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
        return recursion(cardPoints, k, 0, cardPoints.size() - 1);
    }

   private:
    int recursion(vector<int>& cardPoints, int k, int low, int high) {
        if (k == 0) return 0;
        return max(cardPoints[low] + recursion(cardPoints, k - 1, low + 1, high), cardPoints[high] + recursion(cardPoints, k - 1, low, high - 1));
    }
};