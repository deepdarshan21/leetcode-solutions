#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Sorting
        Sort the array according to start of every interval
        Then make interval accordingly

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(n2)
   Status: Accepted
   Runtime: 76 ms faster than: 23.16%
   Memory Usage: 19.9 MB less than: 32.89%
   Remarks:
*/

class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (auto interval : intervals) {
            if (interval[0] > res[res.size() - 1][1]) {
                res.push_back(interval);
            } else {
                res[res.size() - 1][1] = max(interval[1], res[res.size() - 1][1]);
            }
        }
        return res;
    }
};