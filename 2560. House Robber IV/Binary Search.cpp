#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search
        Use binary search to find the minimum capability of the robot.
        Then check if the robot can finish the task with the capability.
        If it can, then the capability is too large, so we need to decrease it.
        If it can't, then the capability is too small, so we need to increase it.

        For the check function, we use a greedy algorithm to check if the robot can
        finish the task with the capability. We start from the first house, and if the
        capability is larger than the house, then we can finish the task with the
        capability. If the capability is smaller than the house, then we need to
        increase the capability. If the capability is equal to the house, then we need
        to increase the capability and move to the next house. We need to do this until
        we finish all the houses or we don't have enough capability to finish the task.

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Accepted
   Runtime: 198 ms faster than: 100%
   Memory Usage: 57 MB less than: 100%
   Remarks:
*/

class Solution {
   public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int low, mid, high;
        low = INT_MAX;
        high = INT_MIN;
        for (int i = 0; i < n; i++) {
            low = min(low, nums[i]);
            high = max(high, nums[i]);
        }
        auto check = [&](int mid) -> bool {
            int tmp = k;
            for (int i = 0; i < n; i++) {
                if (nums[i] <= mid) {
                    tmp--;
                    if (tmp == 0) return true;
                    i++;
                }
            }
            return false;
        };
        while (low < high) {
            mid = low + (high - low) / 2;
            if (check(mid))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};