#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force
        Check for every possible quadruplets

   Edge Cases:
        1. "nums" size smaller then 4

   Time Complexity: O(n^4) Space: O(n^4)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
*/

class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) {
            return {};
        }
        vector<vector<int>> quadruplets;
        int A, B, C, D, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            A = nums[i];
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n; j++) {
                B = nums[j];
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                for (int k = j + 1; k < n; k++) {
                    C = nums[k];
                    if (k > j + 1 && nums[k] == nums[k - 1]) {
                        continue;
                    }
                    for (int l = k + 1; l < n; l++) {
                        D = nums[l];
                        if ((A + B + C + D) > target) {
                            break;
                        }
                        if (l > k + 1 && nums[l] == nums[l - 1]) {
                            continue;
                        }
                        if ((A + B + C + D) == target) {
                            quadruplets.push_back({A, B, C, D});
                        }
                    }
                }
            }
        }
        return quadruplets;
    }
};