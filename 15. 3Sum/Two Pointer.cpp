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
   Runtime: 63 ms faster than: 92.45%
   Memory Usage: 20 MB less than: 66.86%
*/

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) {
            return {};
        }
        vector<vector<int>> triplets;
        int A, B, C, sum, low, high;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                break;
            }
            A = nums[i];
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            low = i + 1;
            high = nums.size() - 1;
            while (low < high) {
                B = nums[low];
                C = nums[high];
                sum = A + B + C;
                if (sum == 0) {
                    triplets.push_back({A, B, C});
                    while (low < high && nums[low] == B) {
                        low++;
                    }
                    while (low < high && nums[high] == C) {
                        high--;
                    }
                } else if (sum > 0) {
                    high--;
                } else {
                    low++;
                }
            }
        }
        return triplets;
    }
};