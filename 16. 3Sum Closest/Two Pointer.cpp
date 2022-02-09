#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Two Pointer
        First sort the input vector, then fisrt take one value using normal looping
        and then use two pointer approach to find remaining two element

   Edge Cases:
        1, While taking first element as closest triplet check that if we used before

   Time Complexity: O(n^2) Space: O(1)
   Status: Accepted
   Runtime: 852 ms faster than: 5.01%
   Memory Usage: 10.1 MB less than: 12.01%
*/

class Solution {
   public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closestSum, diff = INT_MAX;
        int A, B, C, sum, n = nums.size(), low, high, tempDiff;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            A = nums[i];
            low = i + 1;
            high = n - 1;
            while (low < high) {
                B = nums[low];
                C = nums[high];
                sum = A + B + C;
                tempDiff = target - sum;
                if (diff > abs(tempDiff)) {
                    diff = abs(tempDiff);
                    closestSum = sum;
                }
                if (tempDiff == 0) {
                    return closestSum;
                } else if (tempDiff > 0) {
                    low++;
                } else {
                    high--;
                }
            }
        }
        return closestSum;
    }
};