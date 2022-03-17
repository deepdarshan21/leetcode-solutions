#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Recursion


   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 5.90 MB less than: 80.08%
   Remarks:
*/

class Solution {
   public:
    int fib(int n) {
        if (n == 0 || n == 1) {
            return n;
        }
        int t0 = 0, t1 = 1, t2;
        int i = 2;
        while (i <= n) {
            t2 = t1 + t0;
            t0 = t1;
            t1 = t2;
            i++;
        }
        return t2;
    }
};