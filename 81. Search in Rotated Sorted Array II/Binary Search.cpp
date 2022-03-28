#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search
        try to find the correct part where element can exist.

   Edge Cases: if mid element, low element and high element have same value

   Time Complexity: O(logn) Space: O(1)
   Status: Accepted
   Runtime: 19 ms faster than: 6.56%
   Memory Usage: 13.8 MB less than: 99.50%
   Remarks:
*/

class Solution {
   public:
    bool search(vector<int>& nums, int target) {
        int low = 0, mid, high = nums.size() - 1;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return true;
            } else {
                if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                    low++;
                    high--;
                } else {
                    if (nums[low] <= nums[mid]) {
                        // low to mid is sorted
                        if (nums[low] <= target && nums[mid] > target) {
                            high = mid - 1;
                        } else {
                            low = mid + 1;
                        }
                    } else {
                        // mid to high is sorted
                        if (nums[mid] < target && nums[high] >= target) {
                            low = mid + 1;
                        } else {
                            high = mid - 1;
                        }
                    }
                }
            }
        }
        return false;
    }
};