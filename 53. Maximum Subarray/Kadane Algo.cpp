#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Kadane's Algo
        Initialize:
            max_so_far = INT_MIN
            max_ending_here = 0

        Loop for each element of the array
            (a) max_ending_here = max_ending_here + a[i]
            (b) if(max_so_far < max_ending_here)
                max_so_far = max_ending_here
            (c) if(max_ending_here < 0)
                max_ending_here = 0
        return max_so_far

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 138 ms faster than: 62.99%
   Memory Usage: 67.7 MB less than: 54.64%
   Remarks:
*/

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (maxSum < sum) {
                maxSum = sum;
            }
            if (sum < 0) {
                sum = 0;
            }
        }
        return maxSum;
    }
};