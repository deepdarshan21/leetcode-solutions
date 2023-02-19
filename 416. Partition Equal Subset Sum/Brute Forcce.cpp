#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force
        Every element can be either in the first subset or the second subset.

   Edge Cases:

   Time Complexity: O(2^n) Space: O(n)
   Status:  Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        auto rec = [&](auto rec, int i, int sum1, int sum2) -> bool {
            if (i == n) return sum1 == sum2;
            return rec(rec, i + 1, sum1 + nums[i], sum2) || rec(rec, i + 1, sum1, sum2 + nums[i]);
        };
        return rec(rec, 0, 0, 0);
    }
};