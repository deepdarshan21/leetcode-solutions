#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Sorting

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Accepted
   Runtime: 236 ms faster than: 79.09%
   Memory Usage: 65.6 MB less than: 66.76%
   Remarks:
*/

class Solution {
   public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int val = nums[0], idx = 0, res = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                while (idx < n && (val <= nums[i] || val >= nums[idx])) {
                    val = nums[idx] + 1;
                    idx++;
                }
                // cout<<nums[i]<<" "<<val<<endl;
                res += (val - nums[i]);
                val++;
            }
        }
        return res;
    }
};