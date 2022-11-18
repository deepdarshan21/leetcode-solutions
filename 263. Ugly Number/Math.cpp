#include <bits/stdc++.h>
using namespace std;

/*
   Approach: math

   Edge Cases:

   Time Complexity: O(logn) Space: O(1)
   Status: Accepted
   Runtime: 3 ms faster than: 65.96%
   Memory Usage: 5.8 MB less than: 69.56%
   Remarks:
*/

class Solution {
   public:
    bool isUgly(int n) {
        if (n < 1) return false;
        while (n != 1) {
            if (n % 2 != 0 && n % 3 != 0 && n % 5 != 0) return false;
            if (n % 2 == 0)
                n /= 2;
            else if (n % 3 == 0)
                n /= 3;
            else if (n % 5 == 0)
                n /= 5;
        }
        return true;
    }
};