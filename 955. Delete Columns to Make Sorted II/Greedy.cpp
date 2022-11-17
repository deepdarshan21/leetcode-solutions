#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Greedy

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n)
   Status: Accepted
   Runtime: 17 ms faster than: 59.21%
   Memory Usage: 10 MB less than: 73.68%
   Remarks:
*/

class Solution {
   public:
    int minDeletionSize(vector<string>& strs) {
        int res = 0, n = strs.size(), m = strs[0].size();
        vector<bool> isSorted(n, false);
        for (int j = 0; j < m; j++) {
            int i;
            for (i = 1; i < n; i++) {
                if (!isSorted[i] && strs[i - 1][j] > strs[i][j]) {
                    res++;
                    break;
                }
            }
            if (i < n) continue;
            for (i = 1; i < n; i++) {
                isSorted[i] = isSorted[i] || strs[i - 1][j] < strs[i][j];
            }
        }
        return res;
    }
};