#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search


   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Wrong Answer
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks: Negative number makes this algo fails here also
*/

class Solution {
   public:
    int shortestSubarray(vector<int>& nums, int k) {
        int low = 1, mid, high = nums.size(), res = -1;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (isPossible(nums, k, mid)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }

   private:
    bool isPossible(vector<int>& nums, int k, int toCheck) {
        int sum = 0;
        for (int i = 0; i < toCheck; i++) {
            sum += nums[i];
        }
        if (sum >= k) {
            return true;
        }
        for (int i = k; i < nums.size(); i++) {
            sum -= nums[i - k] + nums[i];
            if (sum >= k) {
                return true;
            }
        }
        return false;
    }
};