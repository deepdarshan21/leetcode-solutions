#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < ((i + 1 + indexDiff) > n ? n : (i + 1 + indexDiff)); j++) {
                if (abs(nums[i] - nums[j]) <= valueDiff) return true;
            }
        }
        return false;
    }
};