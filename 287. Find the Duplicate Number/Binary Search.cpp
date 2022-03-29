#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search
        Count the freq of elements who are smaller than equal to mid. And update low or high
        accordingly.

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Accepted
   Runtime: 212 ms faster than: 28.57%
   Memory Usage: 61.2 MB less than: 91.55%
   Remarks:
*/

class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        int low = 0, mid, high = nums.size() - 1;
        while (low <= high) {
            mid = low + (high - low) / 2;
            int tempCnt = 0;
            for (int num : nums) {
                if (num <= mid) {
                    tempCnt++;
                }
            }
            if (tempCnt <= mid) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};