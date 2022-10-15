#include <bits/stdc++.h>
using namespace std;

/*
   Approach:Binary Search
        In the range of 0 to 1e9 try to find the answer

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Accepted
   Runtime: 324 ms faster than: 25%
   Memory Usage: 71.2 MB less than: 12.50%
   Remarks:
*/

class Solution {
   public:
    int minimizeArrayValue(vector<int>& nums) {
        int low = 0, high = INT_MAX, mid, res = INT_MAX;
        while (low <= mid) {
            mid = low + (high - low) / 2;
            if (isValid(nums, mid)) {
                high = mid;
                res = mid;
            } else
                low = mid + 1;
        }
        return res;
    }
    bool isValid(vector<int>& nums, int mid) {
        int sum = 0, maxSum = mid;
        for (int num : nums) {
            sum += num;
            if (sum > mid) return false;
            maxSum += mid;
        }
        return true;
    }
};