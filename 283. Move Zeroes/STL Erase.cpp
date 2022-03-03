#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Using STL's Erase function

   Edge Cases:

   Time Complexity: O(n^2) Space: O(1)
   Status: Accepted
   Runtime: 120 ms faster than: 11.96%
   Memory Usage: 19.3 MB less than: 58.48%
   Remarks:
*/

class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size(), i = 0;
        while (i < len) {
            if (nums[i] == 0) {
                nums.erase(nums.begin() + i);
                nums.push_back(0);
                len--;
            } else {
                i++;
            }
        }
    }
};