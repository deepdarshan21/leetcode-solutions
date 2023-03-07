#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Sliding Window
        Maintain two pointers j and min(prevMinK, prevMaxK) such that j is the index of the
        last element that is not in the range [minK, maxK] and min(prevMinK, prevMaxK) is
        the index of the last element that is in the range [minK, maxK]. For each index i,
        increment the count by min(prevMinK, prevMaxK) - j.

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 122 ms faster than: 38.88%
   Memory Usage: 70.4 MB less than: 81.21%
   Remarks:
*/

class Solution {
   public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long res = 0;
        int j = -1, prevMinK = -1, prevMaxK = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] < minK || nums[i] > maxK) j = i;
            if (nums[i] == minK) prevMinK = i;
            if (nums[i] == maxK) prevMaxK = i;
            res += max(0, min(prevMinK, prevMaxK) - j);
        }
        return res;
    }
};