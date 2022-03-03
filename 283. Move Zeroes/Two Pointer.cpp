#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Two Pointer
        Swap the non zero number with the first zero in that array at that point

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 54 ms faster than: 18.17%
   Memory Usage: 19.1 MB less than: 83.80%
   Remarks:
*/

class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        for (int firstZero = 0, i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[firstZero++], nums[i]);
            }
        }
    }
};