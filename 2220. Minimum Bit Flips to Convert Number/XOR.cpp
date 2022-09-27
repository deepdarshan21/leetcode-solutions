#include <bits/stdc++.h>
using namespace std;

/*
   Approach: XOR and then count number of ones

   Edge Cases:

   Time Complexity: O(1) Space: O(1)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 5.9 MB less than: 27.13%
   Remarks:
*/

class Solution {
   public:
    int minBitFlips(int start, int goal) {
        int temp = goal ^ start;
        int count = 0;
        while (temp != 0) {
            temp = temp & (temp - 1);
            count++;
        }
        return count;
    }
};