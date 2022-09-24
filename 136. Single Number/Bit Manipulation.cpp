#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Bit Manipulation
    XOR of two same number is 0

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 37 ms faster than: 49.71%
   Memory Usage: 17 MB less than: 53.60%
   Remarks:
*/

class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int num : nums) res = res ^ num;
        return res;
    }
};