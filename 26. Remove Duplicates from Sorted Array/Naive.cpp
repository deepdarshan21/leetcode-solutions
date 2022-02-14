#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force


   Edge Cases:


   Time Complexity: O(n^2) Space: O(1)
   Status: Accepted
   Runtime: 608 ms faster than: 5.01%
   Memory Usage: 18.5 MB less than: %
*/

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                nums.erase(nums.begin() + i);
                i--;
            }
        }
        return nums.size();
    }
};