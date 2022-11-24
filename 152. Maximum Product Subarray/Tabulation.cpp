#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Tabulation

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 20 ms faster than: 25%
   Memory Usage: 13.7 MB less than: 94%
   Remarks:
*/

class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int imax = nums[0], imin = nums[0], res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) swap(imax, imin);
            imax = max(nums[i], nums[i] * imax);
            imin = min(nums[i], nums[i] * imin);
            res = max(res, imax);
        }
        return res;
    }
};