#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Greedy Two Pointer
        First sort the array, and simply use two pointer as is tokens[i]<power increase score by one else
        decrease the score in greed of power

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 10.6 MB less than: 67.18%
   Remarks: Decrease score only if there is possiblity to increase score atleast by one
*/

class Solution {
   public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0;
        sort(tokens.begin(), tokens.end());
        int low = 0, high = tokens.size() - 1;
        while (low <= high) {
            if ((power - tokens[low]) >= 0) {
                power -= tokens[low];
                score++;
                low++;
            } else if (score > 0 && (high - low) != 0) {
                power += tokens[high];
                score--;
                high--;
            } else {
                high--;
            }
        }
        return score;
    }
};