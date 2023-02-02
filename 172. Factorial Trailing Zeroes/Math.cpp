#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Math

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status:  Accepted
   Runtime: 3 ms faster than: 44%
   Memory Usage: 6 MB less than: 63%
   Remarks:
*/

class Solution {
   public:
    int trailingZeroes(int n) {
        int res = 0;
        for (int i = 5; i <= n; i += 5) {
            int tmp = i;
            while (tmp % 5 == 0) {
                res++;
                tmp /= 5;
            }
        }
        return res;
    }
};