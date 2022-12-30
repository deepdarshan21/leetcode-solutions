#include <bits/stdc++.h>
using namespace std;

/*
   Approach: use the input array as extra space

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 44 ms faster than: 95.92%
   Memory Usage: 31.4 MB less than: 81.88%
   Remarks:
*/

class Solution {
   public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n) nums[i] = n + 1;
        }
        for (int i = 0; i < n; i++) {
            int id = abs(nums[i]);
            if (id > n) continue;
            id--;
            if (nums[id] > 0) nums[id] = -nums[id];
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) return i + 1;
        }
        return n + 1;
    }
};