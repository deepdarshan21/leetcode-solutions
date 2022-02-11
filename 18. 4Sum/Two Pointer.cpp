#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Two Pointer


   Edge Cases:
        1. Size of "nums" is smaller than 4
        2. Sum of a single quadruplet is greater than "INT_MAX" - Overflow

   Time Complexity: O(n^3) Space: O(n^4)
   Status: Accepted
   Runtime: 50 ms faster than: 82.89%
   Memory Usage: 13 MB less than: 91.42%
*/

class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) {
            return {};
        }
        vector<vector<int>> quadruplets;
        int A, B, C, D, n = nums.size(), sum, newTarget;
        bool isNegativeTarget = false;
        if (target < 0) {
            isNegativeTarget = true;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            A = nums[i];
            if (!isNegativeTarget && A > target) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n; j++) {
                B = nums[j];
                if (!isNegativeTarget && (A + B) > target) {
                    break;
                }
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                newTarget = target - A - B;
                int low = j + 1, high = n - 1;
                while (low < high) {
                    C = nums[low];
                    D = nums[high];
                    sum = C + D;
                    if (sum == newTarget) {
                        quadruplets.push_back({A, B, C, D});
                        while (low < high && nums[low] == C) {
                            low++;
                        }
                        while (low < high && nums[high] == D) {
                            high--;
                        }
                    } else if (sum > newTarget) {
                        high--;
                    } else {
                        low++;
                    }
                }
            }
        }
        return quadruplets;
    }
};