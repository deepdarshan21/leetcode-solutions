#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Bit Manipulation


   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 36 ms faster than: 25.30%
   Memory Usage: 22.3 MB less than: 62.93%
   Remarks:
*/

class Solution {
   public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans ^= nums[i];
        }
        return ans;
    }
};