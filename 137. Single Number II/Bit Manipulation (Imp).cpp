#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Bit Manipulation(Imp)


   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status:Accepted
   Runtime: 11 ms faster than: 78.08%
   Memory Usage: 9.6 MB less than: 59.60%
   Remarks:
*/

class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (int num : nums) {
            ones = (ones ^ num) & (~twos);
            twos = (twos ^ num) & (~ones);
        }
        return ones;
    }
};