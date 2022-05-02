#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Two Pointer


   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 4 ms faster than: 97.86%
   Memory Usage: 16.1 MB less than: 95.88%
   Remarks:
*/

class Solution {
   public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        while (start < end) {
            if (nums[start] % 2 == 0) {
                start++;
            } else {
                swap(nums[start], nums[end]);
                end--;
            }
        }
        return nums;
    }
};