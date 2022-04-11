#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search(find how many time array is been sorted)

   Edge Cases:

   Time Complexity: O(log(n)) Space: O(1)
   Status: Accepted
   Runtime: 8 ms faster than: 58.62%
   Memory Usage: 12.3 MB less than: 19.15%
   Remarks:
*/

class Solution {
   public:
    int findMin(vector<int>& nums) {
        int low = 0, mid, high = nums.size() - 1;
        while (low < high) {
            mid = low + (high - low) / 2;
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
            } else {
                if (nums[mid] > nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }
        }
        return nums[low];
    }
};