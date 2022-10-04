#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Recursion

   Edge Cases:

   Time Complexity: O(n) Space: O(logn)
   Status: Wrong Answer
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks: Will fail in when n is INT_MAX;
*/

class Solution {
   public:
    int integerReplacement(int n) {
        if (n == 1) return 0;
        if (n % 2 == 0) return 1 + integerReplacement(n / 2);
        if (n == INT_MAX) return 1 + integerReplacement(n - 1);
        return 1 + min(integerReplacement(n - 1), integerReplacement(n + 1));
    }
};