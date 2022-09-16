#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O(k) Space: O(1)
   Status: Wrong answer
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks: Will fail in testcases because array is not sorted;
*/

class Solution {
   public:
    int maxScore(vector<int>& cardPoints, int k) {
        int score = 0;
        int low = 0, high = cardPoints.size() - 1;
        while (low <= high && k > 0) {
            if (cardPoints[low] > cardPoints[high]) {
                score += cardPoints[low];
                low++;
            } else {
                score += cardPoints[high];
                high--;
            }
            k--;
        }
        return score;
    }
};