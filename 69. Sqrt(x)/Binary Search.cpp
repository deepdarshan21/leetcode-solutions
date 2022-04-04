#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search
        Think like you are given list of interges from 0 to x and then you need to min interger
        who multiply with itself and result to equal to or smaller than x

   Edge Cases:
        1. If x is zero => runtime error will occur as devide by zero case will ancounter.

   Time Complexity: O(log(n)) Space: O(1)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 5.8 MB less than: 95.40%
   Remarks:
*/

class Solution {
   public:
    int mySqrt(int x) {
        int low = 1, high = x, mid;
        int res = 0;
        if (x == 0) {
            return res;
        }
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (mid == (x / mid)) {
                return mid;
            } else {
                if (mid < (x / mid)) {
                    res = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return res;
    }
};