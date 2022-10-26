#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force


   Edge Cases:

   Time Complexity: O(n^2) Space: O(1)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum, n = nums.size();
        for (int i = 0; i < n; i++) {
            sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if ((j - i + 1) >= 2 && sum % k == 0) return true;
            }
        }
        return false;
    }
};