#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 82 ms faster than: 54%
   Memory Usage: 12.1 MB less than: 72%
   Remarks:
*/

class Solution {
   public:
    int minDeletionSize(vector<string>& strs) {
        int res = 0;
        int n = strs.size(), m = strs[0].size();
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                if (i > 0 && strs[i - 1][j] > strs[i][j]) {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};