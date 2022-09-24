#include <bits/stdc++.h>
using namespace std;

/*
   Approach: XOR

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 49 ms faster than: 21.18%
   Memory Usage: 18.1 MB less than: 20.18%
   Remarks:
*/

class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = res ^ (i + 1);
        }
        for (int num : nums) {
            res = res ^ num;
        }
        return res;
    }
};