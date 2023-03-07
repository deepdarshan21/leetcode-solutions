#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force
        From each index i, find the minimum and maximum value in the subarray
        nums[i..j] and check if it is equal to minK and maxK respectively.
        If yes, increment the count by 1.

   Edge Cases:

   Time Complexity: O(n^2) Space: O(1)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long res = 0;
        for (int i = 0; i < n; i++) {
            int minVal = nums[i], maxVal = nums[i];
            for (int j = i; j < n; j++) {
                minVal = min(minVal, nums[j]);
                maxVal = max(maxVal, nums[j]);
                if (minVal == minK && maxVal == maxK) {
                    res++;
                }
            }
        }
        return res;
    }
};