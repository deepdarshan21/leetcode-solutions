#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Sorting

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Accepted
   Runtime: 40 ms faster than: 64.18%
   Memory Usage: 15.5 MB less than: 24.50%
   Remarks:
*/

class Solution {
   public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), res = nums[0] - nums[n - 1];
        for (int i = 0; i < n - 1; i++)
            res = min(res, max(nums[n - 1] - k, nums[i] + k) - min(nums[0] + k, nums[i + 1] - k));
        return res;
    }
};