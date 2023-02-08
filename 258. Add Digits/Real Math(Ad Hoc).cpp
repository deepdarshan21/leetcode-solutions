#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Math
        By observation, we can find that the result of this problem is
        periodic, i.e. the result of addDigits(num) is periodic with
        period 9. So we can use the following formula to calculate the
        result:
            addDigits(num) = 1 + (num - 1) % 9

   Edge Cases:

   Time Complexity: O(1) Space: O(1)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 6 MB less than: 64%
   Remarks:
*/

class Solution {
   public:
    int addDigits(int num) {
        if (num == 0) return 0;
        int tmp = num % 9;
        if (tmp == 0) return 9;
        return tmp;
    }
};