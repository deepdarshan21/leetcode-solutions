#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Accepted
   Runtime: 697 ms faster than: 23.08%
   Memory Usage: 76.9 MB less than: 76.92%
   Remarks:
*/

class Solution {
   public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int low = INT_MAX, high = 0;
        int n = nums.size();
        for (int num : nums) {
            low = min(low, num);
            high = max(high, num);
        }
        long long mid, res = LLONG_MAX;
        while (low <= high) {
            mid = low + (high - low) / 2;
            long long temp, temp1, temp2;
            temp = getScore(nums, cost, mid);
            temp1 = getScore(nums, cost, mid + 1);
            temp2 = getScore(nums, cost, mid - 1);
            if (temp <= temp1 && temp <= temp2) {
                res = temp;
                break;
            }
            if (temp < temp1) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }
    long long getScore(vector<int>& nums, vector<int>& cost, long long target) {
        long long score = 0;
        for (int i = 0; i < nums.size(); i++) {
            score += abs(nums[i] - target) * cost[i];
        }
        return score;
    }
};