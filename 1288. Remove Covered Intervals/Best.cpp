#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Custom Sorting
        Sort the given 2D vector according to lower limit and if lower limit are same then upper limit
        Then count the number of elements smaller then current maximum.

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Accepted
   Runtime: 127 ms faster than: 12.94%
   Memory Usage: 28.7 MB less than: 11.18%
   Remarks:
*/

class Solution {
   public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
            if (a[0] != b[0]) {
                return a[0] < b[0];
            } else {
                return a[1] > b[1];
            }
        });
        int count, maxUpper = intervals[0][1];
        for (int i = 0; i < intervals.size(); i++) {
            if (maxUpper >= intervals[i][1]) {
                count++;
            } else {
                maxUpper = intervals[i][1];
            }
        }
        return intervals.size() - count;
    }
};