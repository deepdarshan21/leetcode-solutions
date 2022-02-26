#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force
        Check for every possible case

   Edge Cases:

   Time Complexity: O(n^2) Space: O(1)
   Status: Time Limit Exceeeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN, sum;
        for (int i = 0; i < nums.size(); i++) {
            sum = 0;
            int size = 1;
            while (i + size - 1 < nums.size()) {
                sum += nums[i + size - 1];
                if (sum > maxSum) {
                    maxSum = sum;
                }
                size++;
            }
        }
        return maxSum;
    }
};