#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search


   Edge Cases:

   Time Complexity: O(logn) Space: O(1)
   Status: Accepted
   Runtime: 4 ms faster than: 82.50%
   Memory Usage: 9.8 MB less than: 23.37%
   Remarks:
*/

class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, mid, ans;
        if (nums[low] >= target) {
            return low;
        }
        if (nums[high] < target) {
            return high + 1;
        }
        while (low < high) {
            mid = low + (high - low) / 2;
            if (nums[mid] == target || (nums[mid] > target && nums[mid - 1] < target)) {
                ans = mid;
                break;
            } else if (nums[mid] < target && nums[mid + 1] > target) {
                ans = mid + 1;
                break;
            }
            if (target > nums[mid]) {
                low = mid + 1;
            } else if (target < nums[mid]) {
                high = mid;
            }
        }
        return ans;
    }
};