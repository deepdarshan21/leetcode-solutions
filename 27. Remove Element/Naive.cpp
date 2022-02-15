#include <bits/stdc++.h>
using namespace std;

/*
   Approach:
        Erase the element who's value is equal to "val"

   Edge Cases:


   Time Complexity: O(n^2) Space: O(1)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 8.7 MB less than: 92.17%
*/

class Solution {
   public:
    int removeElement(vector<int>& nums, int val) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                nums.erase(nums.begin() + i);
                i--;
            }
        }
        return nums.size();
    }
};