#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Greedy

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 326 ms faster than: 5.01%
   Memory Usage: 109.6 MB less than: 5.65%
   Remarks:
*/

class Solution {
   public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size(), min1 = INT_MAX, min2 = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (nums[i] < min1)
                min1 = nums[i];
            else if (nums[i] < min2 && nums[i] > min1)
                min2 = nums[i];
            else if (nums[i] > min2)
                return true;
        }
        return false;
    }
};