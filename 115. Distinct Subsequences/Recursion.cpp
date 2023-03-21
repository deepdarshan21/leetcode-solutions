#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Recursive

   Edge Cases:

   Time Complexity: O(2^n) Space: O(n)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();

        auto rec = [&](auto self, int i, int j) -> int {
            if (j == m) return 1;
            if (i == n) return 0;

            int take = 0, notTake = 0;
            if (s[i] == t[j]) {
                take = self(self, i + 1, j + 1);
            }
            notTake = self(self, i + 1, j);

            return take + notTake;
        };

        return rec(rec, 0, 0);
    }
};