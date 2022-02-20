#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force
        Run two loops nested loops, one for super set and one for subset,
        if subset found for given super set then remove it.

   Edge Cases:
        1. First is subset of any of the remaining elements => restart subset loop

   Time Complexity: O(n^3) Space: O(1)
   Status: Accepted
   Runtime: 284 ms faster than: 5.04%
   Memory Usage: 11.4 MB less than: 59.43%
   Remarks:
*/

class Solution {
   public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        for (int i = 0; i < intervals.size(); i++) {
            for (int j = 0; j < intervals.size(); j++) {
                if (i == j) {
                    continue;
                }
                if (intervals[i][0] <= intervals[j][0] && intervals[i][1] >= intervals[j][1]) {
                    intervals.erase(intervals.begin() + j);
                    j--;
                    i--;
                }
                // edge case
                if (i < 0) {
                    break;
                }
            }
        }
        return intervals.size();
    }
};