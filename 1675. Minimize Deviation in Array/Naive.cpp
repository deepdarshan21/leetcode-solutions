#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force
        try decreasing max difference by either multipling lowest value of array of dividing
        maximum value of vector by 2

   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Wrong Answer/TLE
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks: Multiple edge case are there =>in starting multiply all the odd number by 2
*/

class Solution {
   public:
    int minimumDeviation(vector<int>& nums) {
        int min, max, minDiff = INT_MAX, diff;
        while (true) {
            // cout << "1" << endl;
            min = min_element(nums.begin(), nums.end()) - nums.begin();
            max = max_element(nums.begin(), nums.end()) - nums.begin();
            diff = nums[max] - nums[min];
            if (minDiff > diff) {
                minDiff = diff;
            }
            if (nums[min] % 2 == 0 && nums[max] % 2 == 0) {
                nums[min] /= 2;
                nums[max] /= 2;
                min = min_element(nums.begin(), nums.end()) - nums.begin();
                max = max_element(nums.begin(), nums.end()) - nums.begin();
                int tempDiff = nums[max] - nums[min];
                if (tempDiff > minDiff) {
                    break;
                } else {
                    continue;
                }
            }
            if (nums[min] % 2 == 1 && nums[max] % 2 == 1) {
                nums[min] *= 2;
                // nums[max] *= 2;
                min = min_element(nums.begin(), nums.end()) - nums.begin();
                max = max_element(nums.begin(), nums.end()) - nums.begin();
                int tempDiff = nums[max] - nums[min];
                if (tempDiff >= minDiff) {
                    break;
                } else {
                    continue;
                }
            }
            if ((nums[min] % 2 == 0 && nums[max] % 2 == 1) || ((nums[min] % 2 == 1 && nums[max] % 2 == 0) && (2 * nums[min] - nums[max] > minDiff) && (nums[min] - nums[max] / 2 > minDiff))) {
                break;
            }
            if (nums[min] % 2 == 1 && nums[max] % 2 == 1) {
                nums[min] *= 2;
                continue;
            }
            if (nums[max] % 2 == 0) {
                nums[max] /= 2;
                continue;
            }
        }
        return minDiff;
    }
};