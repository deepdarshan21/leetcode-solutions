#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search on Answer
        First make the "sums" array and store the sum of elements of "nums" till ith index at ith position.
        then by for loop take the start index of required subarray and by Binary Search(lower bound) find
        the last index of subarray

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Accepted
   Runtime: 22 ms faster than: 10.12%
   Memory Usage: 10.8 MB less than: 7.18%
   Remarks:
*/

class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int> sums(nums.size() + 1);
        sums[0] = 0;
        for (int i = 1; i < sums.size(); i++) {
            sums[i] = nums[i - 1] + sums[i - 1];
        }
        int minLen = INT_MAX, toFind;
        for (int i = 0; i < sums.size(); i++) {
            toFind = target - sums[i];
            auto findIndex = lower_bound(sums.begin(), sums.end(), toFind);
            if (findIndex != sums.end()) {
                minLen = min(minLen, static_cast<int>(findIndex - sums.begin() - i + 1));
            }
        }
        return (minLen == INT_MAX) ? 0 : minLen;
    }
};