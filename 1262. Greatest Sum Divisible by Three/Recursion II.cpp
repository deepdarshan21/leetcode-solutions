#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Recursion
        Start from the first element and try to include it in the sum and
        exclude it from the sum. If the sum is divisible by 3, then update
        the result.

   Edge Cases:

   Time Complexity: O(2^n) Space: O(n)
   Status:	Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        auto rec = [&](auto self, int idx, int rem) -> int {
            if (idx == n) return rem ? INT_MIN : 0;
            int tmp1, tmp2;
            tmp1 = self(self, idx + 1, rem);
            tmp2 = nums[idx] + self(self, idx + 1, (rem + nums[idx]) % 3);
            return max(tmp1, tmp2);
        };
        return rec(rec, 0, 0);
    }
};