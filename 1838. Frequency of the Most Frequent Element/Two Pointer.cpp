#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Two Pointer

   Edge Cases:

   Time Complexity: O(nlogn Space: O(1)
   Status: Accepted
   Runtime: 248 ms faster than: 87.21%
   Memory Usage: 99 MB less than: 59.88%
   Remarks:
*/

class Solution {
   public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = 0, res = 0;
        long long sum = 0;
        while (left <= right && right < nums.size()) {
            if (sum > k) {
                sum -= nums[right] - nums[left];
                left++;
            } else {
                res = max(res, right - left + 1);
                right++;
                if (right < nums.size()) {
                    sum += (long long)(right - left) * (nums[right] - nums[right - 1]);
                }
            }
        }
        return res;
    }
};