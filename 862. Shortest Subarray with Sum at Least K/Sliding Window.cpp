#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Sliding Window
        In this approach we take two pointers start and curr, intialise both of them with 0
        And increases and decrease the window between start and curr, as the sum of elements in
        between the window will just greater than k.

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Wrong Answer
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks: This approach fails with negative numbers
*/

class Solution {
   public:
    int shortestSubarray(vector<int>& nums, int k) {
        int start = 0, curr = 0, sum = 0;
        int res = INT_MAX;
        while (curr < nums.size()) {
            sum += nums[curr];
            if (sum >= k) {
                while ((sum - nums[start]) >= k) {
                    sum -= nums[start];
                    start++;
                }
                res = max(res, (curr - start + 1));
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};