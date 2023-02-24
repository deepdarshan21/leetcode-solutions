#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force


   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 4 ms faster than: 79.59%
   Memory Usage: 11 MB less than: 51.98%
   Remarks:
*/

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        for (int i = 2; i < n; i++) {
            if (nums[i] == nums[i - 1] && nums[i] == nums[i - 2]) {
                nums.erase(nums.begin() + i);
                i--;
                n--;
            }
        }
        return n;
    }
};