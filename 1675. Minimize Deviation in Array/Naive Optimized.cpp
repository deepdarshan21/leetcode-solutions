#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Greedy
        First multiply all the odd numbers from array and then try to decrease the maximum element
        of array until it can't be decrease more(because it becomes odd).

   Edge Cases:

   Time Complexity: O(n^2) Space: O(1)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks: Use "priority_queue" because it automatically sorts the element after modification, so
            decreases the time complexity.
*/

class Solution {
   public:
    int minimumDeviation(vector<int>& nums) {
        int min_i, max_i, minDiff = INT_MAX, diff;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 1) {
                nums[i] *= 2;
            }
        }
        while (true) {
            min_i = min_element(nums.begin(), nums.end()) - nums.begin();
            max_i = max_element(nums.begin(), nums.end()) - nums.begin();
            diff = nums[max_i] - nums[min_i];
            minDiff = min(minDiff, diff);
            if (nums[max_i] % 2 == 1) {
                break;
            }
            nums[max_i] /= 2;
        }
        return minDiff;
    }
};