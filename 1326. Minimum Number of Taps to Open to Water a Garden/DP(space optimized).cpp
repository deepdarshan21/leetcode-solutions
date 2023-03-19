#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP(space optimized)

   Edge Cases:

   Time Complexity: O(n^n) Space: O(1)
   Status: Accepted
   Runtime: 24 ms faster than: 70.48%
   Memory Usage: 14 MB less than: 96.48%
   Remarks:
*/

class Solution {
   public:
    int minTaps(int n, vector<int>& ranges) {
        int min = 0, max = 0, steps = 0, idx = 0;
        while (max < n) {
            for (int i = idx + 1; i < n; i++) {
                if (min >= (i - ranges[i]) && max < (i + ranges[i])) {
                    max = i + ranges[i];
                    idx = i;
                }
            }
            min = max;
            steps++;
        }
        return steps;
    }
};