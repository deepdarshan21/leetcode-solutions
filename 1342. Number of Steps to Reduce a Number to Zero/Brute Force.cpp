#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute FOrce

   Edge Cases:

   Time Complexity: O(1) Space: O(1)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 5.9 MB less than: 25.15%
   Remarks:
*/

class Solution {
   public:
    int numberOfSteps(int num) {
        int count = 0;
        while (!num) {
            if (num % 2 == 0)
                num /= 2;
            else
                num--;
            count++;
        }
        return count;
    }
};