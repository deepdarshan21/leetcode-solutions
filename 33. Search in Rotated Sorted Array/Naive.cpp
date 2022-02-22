#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Linear Search


   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Accepted
   Runtime: 13 ms faster than: 8.00%
   Memory Usage: 11.1 MB less than: 30.00%
   Remarks: It was running in O(nlogn) time complexity but question said that solve it in O(logn) time complexity
*/

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                return i;
            }
        }
        return -1;
    }
};