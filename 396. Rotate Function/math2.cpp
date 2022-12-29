#include <bits/stdc++.h>
using namespace std;

/*
   Approach: F(k) = F(k-1) + sum(a) -sizeOf(a)*last element of array after k-1 rotation

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 142 ms faster than: 98%
   Memory Usage: 95.9 MB less than: 27.51%
   Remarks:
*/

class Solution {
   public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size(), res = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            res += i * nums[i];
            sum += nums[i];
        }

        int temp = res, lastIdx = n - 1;
        for (int i = 1; i < n; i++) {
            temp = temp + sum - n * nums[lastIdx];
            res = max(res, temp);
        }
        return res;
    }
};