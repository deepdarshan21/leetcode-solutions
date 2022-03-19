#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Prifix Sum

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 28 ms faster than: 72.36%
   Memory Usage: 23.9 MB less than: 92.79%
   Remarks:
*/

class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        int first = 1, last = 1;
        for (int i = 0; i < res.size() - 1; i++) {
            first *= nums[i];
            res[i + 1] *= first;
        }
        for (int i = nums.size() - 1; i > 0; i--) {
            last *= nums[i];
            res[i - 1] *= last;
        }
        return res;
    }
};