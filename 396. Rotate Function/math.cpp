#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Rotate array every time calculate the score and take the maximum score

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        vector<pair<int, int>> vp;

        for (int i = 0; i < n; i++) {
            res += i * nums[i];
            vp.push_back({i, nums[i]});
        }

        int diff = 0, maxDiff = 0;
        for (int i = 1; i < n; i++) {
            diff = 0;
            for (int j = 0; j < n; j++) {
                diff += (vp[j].second - nums[(vp[j].first + 1) % n]) * j;
                vp[j].first += 1;
            }
            maxDiff = max(maxDiff, diff);
        }

        return res + maxDiff;
    }
};