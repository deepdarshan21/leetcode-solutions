#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Dp

   Edge Cases: n==1 => 1, n==2 => 2, n==3 => 5

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 5.9 MB less than: 90.70%
   Remarks:
*/

class Solution {
   public:
    int numTilings(int n) {
        int mod = 1e9 + 7;
        int first = 1, second = 2, third = 5;
        if (n == 1) return first;
        if (n == 2) return second;
        if (n == 3) return third;
        int res = 0;
        for (int i = 4; i <= n; i++) {
            res = ((2 * third) % mod + first) % mod;
            first = second;
            second = third;
            third = res;
        }
        return res;
    }
};