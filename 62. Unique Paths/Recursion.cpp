#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Recursion
        ans(i, j) = ans(i+1, j)+ ans(i, j+1)

   Edge Cases:

   Time Complexity: O(n^2) Space: O(logn)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int uniquePaths(int m, int n) {
        auto rec = [&](auto rec, int i, int j) {
            // recursive function
            if (i == (m - 1)) return 1;
            if (j == (n - 1)) return 1;
            return rec(rec, i + 1, j) + rec(rec, i, j + 1);
        };
        return rec(rec, 0, 0);
    }
};