#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Bit Manipulation

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 79 ms faster than: 43.01%
   Memory Usage: 21.3 MB less than: 85.73%
   Remarks:
*/

class Solution {
   public:
    vector<int> findErrorNums(vector<int>& nums) {
        int XOR = 0, n = nums.size();
        for (int i = 0; i < n; i++) XOR ^= (i + 1) ^ nums[i];
        int rightMostDigit = XOR & ~(XOR - 1);
        int xor1 = 0, xor0 = 0;
        for (int i = 0; i < n; i++) {
            if (((i + 1) & rightMostDigit) != 0)
                xor1 ^= (i + 1);
            else
                xor0 ^= (i + 1);
            if ((nums[i] & rightMostDigit) != 0)
                xor1 ^= nums[i];
            else
                xor0 ^= nums[i];
        }
        for (int num : nums) {
            if (xor0 == num) {
                return {xor0, xor1};
            }
        }
        return {xor1, xor0};
    }
};