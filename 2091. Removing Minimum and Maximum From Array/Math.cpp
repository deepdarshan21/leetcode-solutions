#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Math

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accpeted
   Runtime: 365 ms faster than: 16.85%
   Memory Usage: 88.3 MB less than: 79.37%
   Remarks:
*/

class Solution {
   public:
    int minimumDeletions(vector<int>& nums) {
        int res1, res2, res3;
        int mine = INT_MAX, mini, maxe = INT_MIN, maxi;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] > maxe) {
                maxe = nums[i];
                maxi = i;
            }
            if (nums[i] < mine) {
                mine = nums[i];
                mine = i;
            }
        }
        res1 = max(maxi, mini);
        res2 = n - min(maxi, mini) - 1;
        res3 = min(maxi, mini) + n - min(maxi, mini) - 1;
        return min(res1, max(res2, res3));
    }
};