#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Sorting
        First sort the 2D given vector and then check if previous elements upper limit
        is greater then current elements upper limit, if true then remove current element.

   Edge Cases:
        1. Previous elements upper limit is smaller then current elements upper limit but both
        elements lower limits are same.

   Time Complexity: O(n^2) Space: O(1)
   Status: Accepted
   Runtime: 615 ms faster than: 5.04%
   Memory Usage: 11.4 MB less than: 30.26%
   Remarks:
*/

class Solution {
   public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        for (int i = 1; i < intervals.size(); i++) {
            // edge case
            if (intervals[i - 1][1] <= intervals[i][1] && intervals[i - 1][0] == intervals[i][0]) {
                intervals.erase(intervals.begin() + i - 1);
                i--;
                continue;
            }
            if (intervals[i - 1][1] >= intervals[i][1]) {
                intervals.erase(intervals.begin() + i);
                i--;
                continue;
            }
        }
        return intervals.size();
    }
};