#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Two Pointer


   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 61 ms faster than: 26.32%
   Memory Usage: 26 MB less than: 55.48%
   Remarks:
*/

class Solution {
   public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size());
        int low = 0, high = nums.size() - 1;
        int i = nums.size() - 1;
        while (i >= 0) {
            if (abs(nums[low]) > abs(nums[high])) {
                res[i] = nums[low];
                low++;
            } else {
                res[i] = nums[high];
                high--;
            }
            i--;
        }
        return res;
    }
};