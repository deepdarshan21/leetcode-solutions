#include <bits/stdc++.h>
using namespace std;

/*
    Approach: Two Pointer
       

   Edge Cases:
       

   Time Complexity: O(nlogn) Space: O(1)
*/

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            if ((nums[i] + nums[j]) == target) {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
            if ((nums[i] + nums[j]) > target) {
                j--;
            }
            if ((nums[i] + nums[j]) < target) {
                i++;
            }
        }
        return ans;
    }
};