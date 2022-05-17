#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search(Min no. of pages)

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Accepted
   Runtime: 43 ms faster than: 88.91%
   Memory Usage: 22.4 MB less than: 16.08%
   Remarks:
*/

class Solution {
   public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        auto isValid = [&](int divisior) {
            int sum = 0;
            for (auto num : nums) {
                sum += ceil((float)num / divisior);
                if (sum > threshold) {
                    return false;
                }
            }
            return true;
        };

        int low = 1, mid, high = *max_element(nums.begin(), nums.end());
        int res;

        while (low <= high) {
            mid = low + (high - low) / 2;
            if (isValid(mid)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }
};