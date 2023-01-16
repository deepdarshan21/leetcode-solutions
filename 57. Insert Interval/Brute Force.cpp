#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 20 ms faster than: 69.28%
   Memory Usage: 17.7 MB less than: 11.33%
   Remarks:
*/

class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int start = newInterval[0], end = newInterval[1];
        if (n == 0) {
            intervals.push_back(newInterval);
            return intervals;
        }
        if (intervals[n - 1][1] < start) {
            intervals.push_back(newInterval);
            return intervals;
        }
        if (intervals[0][0] > end) {
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        bool done = false;
        vector<vector<int>> res;
        int tmpStart = -1, tmpEnd = -1;
        for (auto itr : intervals) {
            if (!done && tmpStart != -1 && itr[0] > end) {
                res.push_back({tmpStart, tmpEnd});
                done = true;
            }
            if (itr[1] < start || done) {
                res.push_back(itr);  // not in newInterval
            } else if (itr[1] >= start && !done) {
                if (tmpStart == -1 && itr[0] > start && itr[0] > end) {
                    res.push_back(newInterval);
                    res.push_back(itr);
                    done = true;
                    continue;
                } else if (tmpStart == -1)
                    tmpStart = min(itr[0], start);
                tmpEnd = max(itr[1], end);
                // cout<<tmpEnd<<" "<<end<<endl;
            }
        }
        if (!done && tmpStart != -1) {
            res.push_back({tmpStart, tmpEnd});
        }
        return res;
    }
};