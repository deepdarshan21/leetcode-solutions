#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Recursive

   Edge Cases:

   Time Complexity: O(n^n) Space: O(n)
   Status: Accepted
   Runtime: 76 ms faster than: 19%
   Memory Usage: 14.92 MB less than: 72.91%
   Remarks:
*/

class Solution {
   public:
    int minTaps(int n, vector<int>& ranges) {
        auto rec = [&](auto self, int start) -> int {
            if (start >= n) return 0;
            int tmp = 0;
            for (int i = 0; i <= n; i++) {
                if (start >= i - ranges[i]) {
                    tmp = max(tmp, i + ranges[i]);
                }
            }
            if (tmp == start) return -1;
            int res = self(self, tmp);
            if (res == -1) return -1;
            return 1 + res;
        };
        return rec(rec, 0);
    }
};