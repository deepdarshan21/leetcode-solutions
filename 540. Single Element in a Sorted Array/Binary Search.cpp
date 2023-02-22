#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search
        If every number appears twice except one, then for the array before that odd element,
        for every even index, the number at that index is the same as the number at the next index.

   Edge Cases:

   Time Complexity: O(logn) Space: O(1)
   Status: Accepted
   Runtime: 13 ms faster than: 99.77%
   Memory Usage: 22.4 MB less than: 62.93%
   Remarks:
*/

class Solution {
   public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, m;
        while (l < r) {
            m = l + (r - l) / 2;
            if (m % 2 == 0) {
                if (nums[m] == nums[m + 1])
                    l = m + 2;
                else {
                    if (m == 0) return nums[m];
                    if (nums[m] != nums[m - 1])
                        return nums[m];
                    else
                        r = m - 1;
                }
            } else {
                if (nums[m] == nums[m - 1])
                    l = m + 1;
                else {
                    if (m == 0) return nums[m];
                    if (nums[m] != nums[m + 1])
                        return nums[m];
                    else
                        r = m - 1;
                }
            }
        }
        return nums[l];
    }
};