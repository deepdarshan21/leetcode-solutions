#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Wrong Answer
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks: There can be duplicate number with freq more than two.
*/

class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        int res = 0;
        for (int i = 1; i < nums.size(); i++) {
            res ^= i;
        }
        for (int i = 0; i < nums.size(); i++) {
            res ^= nums[i];
        }
        return res;
    }
};