#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Time Limit Exeeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int size = 1; size <= nums.size() - i; size++) {
                if (accumulate(nums.begin() + i, nums.begin() + i + size - 1, 0) == k) {
                    count++;
                }
            }
        }
        return count;
    }
};