#include <bits/stdc++.h>
using namespace std;

/*
    Approach: Brute Force
        Check of every possible triplet's sum and then check is it closest to target or not,
        if true then update values accordingly

   Edge Cases:


   Time Complexity: O(n^3) Space: O(1)
   Status: Accepted
   Runtime: 1042 ms faster than: 5.01%
   Memory Usage: 10.1 MB less than: 11.95%
*/

class Solution {
   public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closestSum, diff = INT_MAX;
        int A, B, C, n = nums.size(), sum;
        for (int i = 0; i < n; i++) {
            A = nums[i];
            for (int j = i + 1; j < n; j++) {
                B = nums[j];
                for (int k = j + 1; k < n; k++) {
                    int C = nums[k];
                    sum = A + B + C;
                    if (diff > abs(target - sum)) {
                        diff = abs(target - sum);
                        closestSum = sum;
                        if (diff == 0) {
                            return closestSum;
                        }
                    }
                }
            }
        }
        return closestSum;
    }
};