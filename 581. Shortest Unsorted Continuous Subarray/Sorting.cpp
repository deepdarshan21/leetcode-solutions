#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Sorting and compare

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(n)
   Status:  Accepted
   Runtime: 44 ms faster than: 48.43%
   Memory Usage: 27.4 MB less than: 46.57%
   Remarks:
*/

class Solution {
   public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sortedNums(nums.begin(), nums.end());

        sort(sortedNums.begin(), sortedNums.end());

        int start, end;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != sortedNums[i]) {
                start = i;
                break;
            }
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] != sortedNums[i]) {
                end = i;
                break;
            }
        }

        if (end - start <= 0) {
            return 0;
        }
        return end - start;
    }
};