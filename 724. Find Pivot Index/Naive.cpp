#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Best Approach


   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 46 ms faster than: 24.32%
   Memory Usage: 31.2 MB less than: 33.40%
   Remarks:
*/

class Solution {
   public:
    int pivotIndex(vector<int>& nums) {
        int sum;
        sum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0, rightSum = sum - nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (leftSum == rightSum) {
                return i - 1;
            }
            leftSum += nums[i - 1];
            rightSum -= nums[i];
        }
        if (leftSum == rightSum) {
            return nums.size() - 1;
        }
        return -1;
    }
};