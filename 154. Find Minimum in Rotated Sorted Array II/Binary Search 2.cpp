#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search
        Use the concept of peak element to find the min element

   Edge Cases:

   Time Complexity: O(logn) Space: O(1)
   Status: Wrong answer
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks: Fail in test case like : [3,4,5,6,2] and [1,1,3]
*/

class Solution {
   public:
    int findMin(vector<int>& nums) {
        int low = 0, mid, high = nums.size() - 1;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if ((mid == 0 || nums[mid - 1] > nums[mid]) && ((mid == nums.size() - 1) || nums[mid + 1] > nums[mid])) {
                return nums[mid];
            } else {
                if (mid != 0 && mid != nums.size() - 1 && (nums[mid - 1] < nums[mid]) || (nums[mid - 1] == nums[mid] && nums[mid + 1] > nums[mid])) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        return 0;
    }
};