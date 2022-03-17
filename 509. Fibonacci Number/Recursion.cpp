#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 5.9 MB less than: 80.08%
   Remarks:
*/

class Solution {
   public:
    int fib(int n) {
        if (n < 2) {
            return n;
        }
        return fib(n) + fib(n - 1);
    }
};