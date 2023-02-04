#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force
        For each removeQueries[i], we can set nums[removeQueries[i]] = 0, and then
        find the maximum sum of a segment in nums.

   Edge Cases:

   Time Complexity: O(n^2) Space: O(1)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n = nums.size();
        auto maxSumOfASegment = [&]() -> long long {
            long long maxSum = 0LL, sum = 0LL;
            for (int i = 0; i < n; i++) {
                if (nums[i] == 0) {
                    sum = 0;
                    continue;
                }
                sum += nums[i];
                maxSum = max(maxSum, sum);
            }
            return maxSum;
        };
        vector<long long> res(n);
        for (int i = 0; i < n; i++) {
            nums[removeQueries[i]] = 0;
            res[i] = maxSumOfASegment();
        }
        return res;
    }
};