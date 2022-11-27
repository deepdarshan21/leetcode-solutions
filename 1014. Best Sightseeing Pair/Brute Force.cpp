#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O(n^2) Space: O(1)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int res = 0, n = values.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                res = max(res, values[i] + values[j] + i - j);
            }
        }
        return res;
    }
};