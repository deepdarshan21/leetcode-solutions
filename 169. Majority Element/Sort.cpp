#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Sorting
        Sort the array and the element at middle will be the element with frequency greater than n/2

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Accepted
   Runtime: 30 ms faster than: 41.73%
   Memory Usage: 19.6 MB less than: 52.27%
   Remarks:
*/

class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};