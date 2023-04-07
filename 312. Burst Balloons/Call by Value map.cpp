#include <bits/stdc++.h>
using namespace std;

/*
   Approach: check for every posibile condition, that is recursion than add momory to fast the solving process
   not recalculating same thing again and again.

   Edge Cases:

   Time Complexity: O(n) Space: O(n*n)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   private:
    map<vector<int>, int> dp;
    int help(vector<int> nums) {
        if (dp.count(nums)) return dp[nums];
        int n = nums.size();
        int res = 0;
        int prev, main, next;
        for (int i = 0; i < n; i++) {
            if (i == 0)
                prev = 1;
            else
                prev = nums[i - 1];
            main = nums[i];
            if (i == n - 1)
                next = 1;
            else
                next = nums[i + 1];
            nums.erase(nums.begin() + i);
            res = max(res, prev * main * next + help(nums));
            nums.insert(nums.begin() + i, main);
        }
        return dp[nums] = res;
    }

   public:
    int maxCoins(vector<int>& nums) {
        return help(nums);
    }
};