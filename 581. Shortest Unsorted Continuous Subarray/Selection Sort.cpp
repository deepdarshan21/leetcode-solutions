#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Selection Sort Implementation


   Edge Cases:

   Time Complexity: O(n^2) Space: O(1)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = INT_MAX, end = INT_MIN;
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] < nums[i]) {
                    start = min(start, i);
                    end = max(end, j);
                }
            }
        }

        return end - start <= 0 ? 0 : end - start + 1;
    }
};