#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Sorting
        First sort the array then check if adjecent element is equal or not.

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status:
   Runtime: 142 ms faster than: 43.93%
   Memory Usage: 46.6 MB less than: 75.42%
   Remarks:
*/

class Solution {
   public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }
        return false;
    }
};