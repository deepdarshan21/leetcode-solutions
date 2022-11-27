#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP (tabulation)

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 140 ms faster than: 39.65%
   Memory Usage: 39.3 MB less than: 97.94%
   Remarks:
*/

class Solution {
   public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int res = 0, curr = 0;
        for (int value : values) {
            res = max(res, curr + value);
            curr = max(curr, value) - 1;
        }
        return res;
    }
};