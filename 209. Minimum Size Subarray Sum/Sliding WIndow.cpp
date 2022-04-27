#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Sliding Window


   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 12 ms faster than: 43.61%
   Memory Usage: 10.6 MB less than: 16.51%
   Remarks:
*/

class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0, minLen = INT_MAX, i = 1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum >= target) {
                minLen = min(minLen, i + 1 - start);
                sum -= nums[start++];
            }
        }
        return (minLen == INT_MAX) ? 0 : minLen;
    }
};