#include <bits/stdc++.h>
using namespace std;

/*
   Approach: MOdified Binary Search


   Edge Cases:

   Time Complexity: O(log(n)) Space: O(1)
   Status: Acceped
   Runtime: 3 ms faster than: 86.10%
   Memory Usage: 8.9 MB less than: 5.09%
   Remarks:
*/

class Solution {
   public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, mid, high = nums.size() - 1;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if ((mid == 0 || nums[mid - 1] < nums[mid]) && (mid == (nums.size() - 1) || nums[mid + 1] < nums[mid])) {
                return mid;
            } else {
                if (mid > 0 && nums[mid - 1] > nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        return -1;
    }
};