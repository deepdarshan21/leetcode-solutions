#include <bits/stdc++.h>
using namespace std;

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */
int guess(int num);

/*
   Approach: Binary Search


   Edge Cases:

   Time Complexity: O(logn) Space: O(1)
   Status: Accepted
   Runtime: 3 ms faster than: 31.67%
   Memory Usage: 5.8 MB less than: 88.75%
   Remarks:
*/

class Solution {
   public:
    int guessNumber(int n) {
        int low = 1, mid, high = n;
        int res;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (guess(mid) == 0) {
                res = mid;
                break;
            } else {
                if (guess(mid) < 0) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        return res;
    }
};