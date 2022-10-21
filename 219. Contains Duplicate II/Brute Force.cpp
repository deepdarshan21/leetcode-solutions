#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Search fir every possible combination using 2 loops

   Edge Cases:

   Time Complexity: O(n^2) Space: O(1)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < ((i + k + 1) > n ? n : (i + k + 1)); j++) {
                if (nums[i] == nums[j]) return true;
            }
        }
        return false;
    }
};