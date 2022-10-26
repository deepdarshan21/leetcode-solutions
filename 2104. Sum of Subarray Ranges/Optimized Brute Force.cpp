#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force

   Edge Cases:

   Time Complexity: O(n^2) Space: O(1)
   Status: Accepted
   Runtime: 88 ms faster than: 54.43%
   Memory Usage: 10.5 MB less than: 73.09%
   Remarks:
*/

class Solution {
   public:
    long long subArrayRanges(vector<int>& nums) {
        long long res = 0;
        int n = nums.size(), minVal, maxVal;
        for (int i = 0; i < n; i++) {
            minVal = INT_MAX;
            maxVal = INT_MIN;
            for (int j = i; j < n; j++) {
                minVal = min(minVal, nums[j]);
                maxVal = max(maxVal, nums[i]);
                res += (maxVal - minVal);
            }
        }
        return res;
    }
};