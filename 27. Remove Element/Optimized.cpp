#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:


   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 8.8 MB less than: 36.52%
*/

class Solution {
   public:
    int removeElement(vector<int>& nums, int val) {
        size_t size = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[size] = nums[i];
                size++;
            }
        }
        return size;
    }
};