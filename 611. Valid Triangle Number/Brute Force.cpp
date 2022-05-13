#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force
        First sort the array, then make every possible triplets and check is it making a valid triplet

   Edge Cases:
        1. If nums size is less then 3, this is because nums.size return unsigned bit
            => in the start of program add a if condition to check if array's size is smaller then 3

   Time Complexity: O() Space: O()
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int triangleNumber(vector<int>& nums) {
        int count = 0;
        if (nums.size() < 3) {
            return count;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            for (int j = i + 1; j < nums.size() - 1; j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    if ((nums[i] + nums[j]) > nums[k]) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};