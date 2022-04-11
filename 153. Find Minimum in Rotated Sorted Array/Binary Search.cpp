#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search (for finding min element)
        Find the mid, then check is it smaller then its neighboring elements or not,
        if not then change low or high accordling

   Edge Cases:

   Time Complexity: O(log(n)) Space: O(1)
   Status: Accepted
   Runtime: 9 ms faster than: 16.94%
   Memory Usage: 10.2 MB less than: 22.35%
   Remarks:
*/

class Solution {
   public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size(), mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if ((mid == 0 || nums[mid - 1] > nums[mid]) && (mid == (nums.size() - 1) || nums[mid + 1] > nums[mid])) {
                return mid;
            } else {
                if (nums[mid] < nums[high]) {
                    high = mid - 1;
                } else {
                    low = mid + 1l;
                }
            }
        }
        return 0;
    }
};