#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 11 ms faster than: 74.52%
   Memory Usage: 16.2 MB less than: 57.28%
   Remarks:
*/

class Solution {
   public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans(nums.size());
        int start = 0, end = nums.size() - 1;
        for (auto num : nums) {
            if (num % 2 == 0) {
                ans[start++] = num;
            } else {
                ans[end--] = num;
            }
        }
        return ans;
    }
};