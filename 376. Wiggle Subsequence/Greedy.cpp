#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Greedy

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 7 MB less than: 96.15%
   Remarks:
*/

class Solution {
   public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size(), count = 0;
        if (n < 2) return n;
        int prevDiff = nums[1] - nums[0], diff;
        count = prevDiff == 0 ? 1 : 2;
        for (int i = 2; i < n; i++) {
            diff = nums[i] - nums[i - 1];
            if ((diff > 0 && prevDiff <= 0) || (diff < 0 && prevDiff >= 0)) {
                count++;
                prevDiff = diff;
            }
        }
        return count;
    }
};