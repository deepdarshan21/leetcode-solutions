#include <bits/stdc++.h>
using namespace std;

/*
   Approach:
        Swap the element at ith with its corresponding correct position in increasing order

   Edge Cases:


   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 32 ms faster than: 13.79%
   Memory Usage: 18.3 MB less than: 93.40%
*/

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int size = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[size - 1] < nums[i]) {
                nums[size++] = nums[i];
            }
        }
        return size;
    }
};