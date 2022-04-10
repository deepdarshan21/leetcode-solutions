#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary search(Allocation of min number of pages)


   Edge Cases:

   Time Complexity: O(nlog(n)) Space: O(1)
   Status: Accepted
   Runtime: 156 ms faster than: 98.96%
   Memory Usage: 118 MB less than: 5.72%
   Remarks: Count in less time can be done by devide as adding takes more linear time.
*/

class Solution {
   public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1, mid, high = *max_element(nums.begin(), nums.end());
        int res;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (isValid(nums, maxOperations, mid)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }
    bool isValid(vector<int> nums, int maxOperation, int mid) {
        int count = 0, i = 0;
        for (auto num : nums) {
            count += num / mid + (num % mid != 0);
            if (count > (maxOperation + nums.size())) {
                return false;
            }
        }
        return true;
    }
};