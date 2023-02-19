#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force
        Just reduce the problem that we need to find a subset that sums up to half of the total sum.
        Then we can use the same approach as the previous problem.

   Edge Cases:

   Time Complexity: O(2^n) Space: O(n)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return false;
        sum /= 2;
        auto rec = [&](auto rec, int i, int sum) -> bool {
            if (sum == 0) return true;
            if (i == n || sum < 0) return false;
            return rec(rec, i + 1, sum - nums[i]) || rec(rec, i + 1, sum);
        };
        return rec(rec, 0, sum);
    }
};