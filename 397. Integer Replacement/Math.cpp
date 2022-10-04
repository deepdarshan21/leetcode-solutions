#include <bits/stdc++.h>
using namespace std;

/*
   Approach: MAth

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 5.7 MB less than: 96.70%
   Remarks:
*/

class Solution {
   public:
    int integerReplacement(int n) {
        int count = 0;
        while (n != 1) {
            if (n % 2 == 0)
                n /= 2;
            else if (n > 14 && ((n + 1) / 2) % 2 == 0)
                n += 1;
            else
                n -= 1;
            count++;
        }
        return count;
    }
};