#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Sorting (Greedy)

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Accepted
   Runtime: 903 ms faster than: 62.08%
   Memory Usage: 89.9 MB less than: 22.32%
   Remarks: If I not use call by reference in this question Time Limit Exceed will happen
*/

class Solution {
   public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &first, vector<int> &second) {
            return first[1] < second[1];
        });
        int last = 0, res = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[last][1] > intervals[i][0])
                res++;
            else
                last = i;
        }
        return res;
    }
};