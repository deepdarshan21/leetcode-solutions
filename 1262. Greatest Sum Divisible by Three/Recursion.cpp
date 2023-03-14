#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Recursion
        Start from the first element and try to include it in the sum and
        exclude it from the sum. If the sum is divisible by 3, then update
        the result.

   Edge Cases:

   Time Complexity: O(2^n) Space: O(n)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        auto rec = [&](auto self, int idx, int sum) -> void {
            if (idx == n) {
                if (sum % 3 == 0) {
                    res = max(res, sum);
                }
                return;
            }
            self(self, idx + 1, sum);
            self(self, idx + 1, sum + nums[idx]);
        };
        rec(rec, 0, 0);
        return res;
    }
};