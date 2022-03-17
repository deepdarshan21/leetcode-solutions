#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force


   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 4 ms faster than: 59.59%
   Memory Usage: 8.5 MB less than: 38.30%
   Remarks:
*/

class Solution {
   public:
    vector<int> runningSum(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            nums[i] = sum;
        }
        return nums;
    }
};