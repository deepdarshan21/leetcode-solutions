#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Tebulation
        Simulate this  problem into fiboncci sequence

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 3 ms faster than: 35%
   Memory Usage: 5.9 MB less than: 82%
   Remarks:
*/

class Solution {
   public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        int n1, n2;
        n1 = 1;
        n2 = 2;
        for (int i = 3; i <= n; i++) {
            int temp = n2;
            n2 = n1 + n2;
            n1 = temp;
        }
        return n2;
    }
};