#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search(upper_bound)
        Same as brute force... but use upper bound to find "max"

   Edge Cases:

   Time Complexity: O(n^2) Space: O(1)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks: Use extra space to store 2's powers
*/

class Solution {
   public:
    int numSubseq(vector<int>& nums, int target) {
        int count = 0;
        const int mod = 1e9 + 7;
        sort(nums.begin(), nums.end());
        for (int min = 0; min < nums.size(); min++) {
            int max = upper_bound(nums.begin() + min, nums.end(), target - nums[min]) - nums.begin() - 1;
            if (max < min) {
                continue;
            }
            int temp = 1;
            for (int i = min; i < max; i++) {
                temp = (temp * 2) % mod;
            }
            count = (count + temp) % mod;
        }
        return count;
    }
};