#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search


   Edge Cases:

   Time Complexity: O(logn) Space: O(1)
   Status: Accepted
   Runtime: 60 ms faster than: 32.53%
   Memory Usage: 27.6 MB less than: 13.43%
   Remarks:
*/

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
};