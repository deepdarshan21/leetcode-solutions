#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status:  Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int sum, res = 0;
        for (int i = 0; i < n; i++) {
            sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[i];
                if (sum % k == 0) res++;
            }
        }
        return res;
    }
};