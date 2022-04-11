#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force
        take an element from vector and try find element smaller then that element in the remaining
        right half of vector

   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            int count = 0;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] > nums[j]) {
                    count++;
                }
            }
            res[i] = count;
        }
        return res;
    }
};