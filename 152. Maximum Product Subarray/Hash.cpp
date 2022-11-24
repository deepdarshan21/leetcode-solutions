#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Wrong Answer
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:[2,-5,-2,-4,3]
*/

class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> ones(n, 0);
        if (nums[n - 1] < 0) ones[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            ones[i] = ones[i + 1];
            if (nums[i] < 0) ones[i]++;
            // cout<<ones[i]<<" ";
        }
        int res = INT_MIN, temp = 1;
        for (int i = 0; i < n; i++) {
            temp *= nums[i];
            res = max(res, temp);
            if (temp == 0)
                temp = 1;
            else if (temp <= 0 && (i == n - 1 || ones[i + 1] < 1))
                temp = 1;
            // cout<<temp<<" ";
        }
        return res;
    }
};