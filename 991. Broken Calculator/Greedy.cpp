#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 5.9 MB less than: 73.18%
   Remarks:
*/

class Solution {
   public:
    int brokenCalc(int startValue, int target) {
        int count = 0;
        while (startValue != target) {
            if (target % 2 == 0 && target > startValue) {
                target /= 2;
            } else if (target > startValue) {
                target += 1;
            } else {
                count += startValue - target;
                break;
            }
            count++;
        }
        return count;
    }
};