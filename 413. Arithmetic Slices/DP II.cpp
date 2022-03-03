#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Dynamic Programming
        Use a DP.cpp approach, but insteed of using a vector for storing number of permutation till that
        number use a variable to store the number of permutation till previous number.

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 7.3 MB less than: 55.42%
   Remarks:
*/

class Solution {
   public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int count = 0;
        if (nums.size() < 3) {
            return count;
        }
        int prev = 0, first, second;
        for (int i = 2; i < nums.size(); i++) {
            first = nums[i] - nums[i - 1];
            second = nums[i - 1] - nums[i - 2];
            if (first == second) {
                prev++;
            } else {
                prev = 0;
            }
            count += prev;
        }
        return count;
    }
};