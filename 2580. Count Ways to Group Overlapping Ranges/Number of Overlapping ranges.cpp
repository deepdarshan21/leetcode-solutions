#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Find number of overlapping subsequences

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Accepted
   Runtime: 340 ms faster than: 70.44%
   Memory Usage: 72.7 MB less than: 68.93%
   Remarks:
*/

class Solution {
   public:
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end());
        int n = ranges.size();
        int idx = 0;
        for (int i = 1; i < n; i++) {
            if (ranges[idx][1] >= ranges[i][0]) {
                ranges[idx][1] = max(ranges[idx][1], ranges[i][1]);
            } else {
                idx++;
                ranges[idx][0] = ranges[i][0];
                ranges[idx][1] = ranges[i][1];
            }
        }
        idx++;
        // cout<<idx<<endl;

        long long res = 1, mod = 1e9 + 7;
        for (int i = 0; i < idx; i++) {
            res = (res * 2) % mod;
        }
        return res;
    }
};