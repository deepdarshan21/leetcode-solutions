#include <bits/stdc++.h>
using namespace std;

/*
    Approach: Two Pointer
        Sort the input vector and then first take first element of triplet using for loop
        and the use 'Two Pointer' approach to find the remaining two elements to triplet

   Edge Cases:
        1. Size of input vector is smaller then 3 -> reducing time

   Time Complexity: O(n^2) Space: O(n^3)
   Status: Accepted
   Runtime: 149 ms faster than: 41.35%
   Memory Usage: 24.7 MB less than: 19.95%
*/

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) {
            return {};
        }
        set<vector<int>> tripletsSet;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int low = i + 1, high = nums.size() - 1, target = 0 - nums[i];
            while (low < high) {
                if (nums[low] + nums[high] == target) {
                    tripletsSet.insert({nums[i], nums[low], nums[high]});
                    low++;
                    high--;
                } else if (nums[low] + nums[high] < target) {
                    low++;
                } else {
                    high--;
                }
            }
        }
        vector<vector<int>> triplets(tripletsSet.begin(), tripletsSet.end());
        return triplets;
    }
};