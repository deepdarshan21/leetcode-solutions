#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search
        Take low and high as 1 and num/2, check if the mid between low and high is required answer
        or not. If not then move low and high accordingly.

   Edge Cases:
        1. If  num if 1, it is square number, return true.

   Time Complexity: O(logn) Space: O(1)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 5.9 MB less than: 17.94%
   Remarks:
        1. multipling mid can genrate some overflow condition
        2. Dividing integer number might fail some test cases as it gives only quitiant after devide
*/

class Solution {
   public:
    bool isPerfectSquare(int num) {
        if (num == 1) {
            return true;
        }
        int low = 1, high = num / 2;
        float mid;
        while (low <= high) {
            mid = low + (high - low) / 2 * 1.0;
            if ((num / mid) == mid) {
                return true;
            } else {
                if ((num / mid) < mid) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        return false;
    }
}
}
;