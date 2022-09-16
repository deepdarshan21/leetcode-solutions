#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O(2^n) Space: O(1)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        return help(nums, multipliers, 0);
    }

   private:
    int help(vector<int> nums, vector<int> multipliers, int i) {
        if (i == multipliers.size()) return 0;
        int res1, res2, temp;
        temp = nums[0];
        nums.erase(nums.begin());
        res1 = multipliers[i] * temp + help(nums, multipliers, i + 1);
        nums.insert(nums.begin() + 0, temp);
        temp = nums[nums.size() - 1];
        nums.pop_back();
        res2 = multipliers[i] * temp + help(nums, multipliers, i + 1);
        return max(res1, res2);
    }
};