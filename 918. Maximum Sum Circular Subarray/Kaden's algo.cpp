#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Kadene's algo

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 99 ms faster than: 72%
   Memory Usage: 41 MB less than: 14%
   Remarks:
*/

class Solution {
   public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, maxSum = INT_MIN;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            maxSum = max(maxSum, sum);
            if (sum < 0) sum = 0;
        }
        vector<int> maxRight(n, 0);
        sum = 0;
        maxRight[n - 1] = nums[n - 1];
        sum += nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            sum += nums[i];
            maxRight[i] = max(sum, maxRight[i + 1]);
        }
        int res = maxSum, leftSum = 0;
        for (int i = 0; i < n - 2; i++) {
            leftSum += nums[i];
            res = max(res, leftSum + maxRight[i + 1]);
        }
        return res;
    }
};