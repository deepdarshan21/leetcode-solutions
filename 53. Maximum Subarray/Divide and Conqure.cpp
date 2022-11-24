#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Divide and Conqure

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Accepted
   Runtime: 439 ms faster than: 5%
   Memory Usage: 67 MB less than: 55%
   Remarks:
*/

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        return help(nums, 0, n - 1);
    }
    int help(vector<int>& nums, int start, int end) {
        if (end <= start) return nums[start];
        int mid = start + (end - start) / 2;
        int sum, maxSum1 = 0, maxSum2 = 0;
        sum = 0;
        for (int i = mid; i >= start; i--) {
            sum += nums[i];
            maxSum1 = max(maxSum1, sum);
        }
        int sum = 0;
        for (int i = mid + 1; i <= end; i++) {
            sum += nums[i];
            maxSum2 = max(sum, maxSum2);
        }
        int temp1 = help(nums, 0, mid);
        int temp2 = help(nums, mid + 1, end);
        return max(maxSum1 + maxSum2, max(temp1, temp2));
    }
};