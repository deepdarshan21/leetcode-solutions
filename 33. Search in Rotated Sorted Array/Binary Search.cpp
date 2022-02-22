#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Modified Binary Search
        Run a loop till start element is smaller then end element
            if mid element is equal to target: return mid
            else if mid element is greater than start element -> array before mid element must be sorted
                if target is smaller than mid element and greater than start element: new end element is mid element -> unrotaed part
                else : new start element is mid element -> roated part
            else -> array after mid must be sorted
                if target is greater than mid element and smaller than end element: new start element is mid element -> unroated side
                else : new end element is mid element -> rotated side
        return -1 -> element not found in array

   Edge Cases:

   Time Complexity: O(logn) Space: O(1)
   Status: Accepted
   Runtime: 3 ms faster than: 84.47%
   Memory Usage: 11.2 MB less than: 30.00%
   Remarks:
*/

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int low = 0, mid, high = nums.size() - 1;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] >= nums[low]) {
                if (target < nums[mid] && target >= nums[low]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (target > nums[mid] && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};