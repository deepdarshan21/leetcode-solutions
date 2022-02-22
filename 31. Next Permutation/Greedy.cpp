#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Greedy
        First found the number which is smaller than its next number and then the element how is
        just greater than fisrt selected element than swap then and sort the vector after first selected
        element's index to end

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 8 ms faster than: 41.29%
   Memory Usage: 12.2 MB less than: 37.00%
   Remarks:
*/

class Solution {
   public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), r = n - 2;
        while (r >= 0 && nums[r] >= nums[r + 1]) {
            r--;
        }
        if (r >= 0) {
            int l = r + 1;
            while (l < n && nums[l] > nums[r]) {
                l++;
            }
            l--;
            swap(nums[r], nums[l]);
        }
        sort(nums.begin() + r + 1, nums.end());
    }
};