#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search(Allocate Minimum number of pages)
        In this approach, we assume X is the answer and then we check is actually X is following
        the given condition or not.
        For assumeing X we use the help of binary search.
        The low of binary search will be max element of array, and high will be sum of all
        elements of array. The mid of them will be our assumption

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Accepted
   Runtime: 4 ms faster than: 53.36%
   Memory Usage: 7.2 MB less than: 73.70%
   Remarks:
*/

class Solution {
   public:
    int splitArray(vector<int>& nums, int m) {
        int low, mid, high;
        int res = -1;
        low = *max_element(nums.begin(), nums.end());
        high = accumulate(nums.begin(), nums.end(), 0);
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (toDecrease(nums, m, mid)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }

   private:
    bool toDecrease(vector<int>& nums, int m, int toCheck) {
        int count = 0, sum = 0;
        count++;
        for (auto num : nums) {
            sum += num;
            if (sum > toCheck) {
                sum = num;
                count++;
            }
            if (count > m) {
                return false;
            }
        }
        return true;
    }
};