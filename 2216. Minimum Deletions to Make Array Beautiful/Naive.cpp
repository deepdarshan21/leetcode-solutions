#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force
        Check for element that are causing array to not me beautiful and remove them.

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks: Erase operation take some extra time.
*/

class Solution {
   public:
    int minDeletion(vector<int>& nums) {
        // int size=nums.size();
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                if ((i + 1) < nums.size()) {
                    if (nums[i] == nums[i + 1]) {
                        nums.erase(nums.begin() + i);
                        i--;
                        count++;
                    }
                }
                if ((i + 1) == nums.size()) {
                    nums.erase(nums.begin() + i);
                    count++;
                    i--;
                }
            }
        }
        return count;
    }
};