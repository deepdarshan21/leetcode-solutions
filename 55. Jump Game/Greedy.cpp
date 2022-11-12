#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Greedy
        Same as Jump II, only differece is insteed of returning jump we will return is lastPos is greater
        than position of last element in array

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 141 ms faster than: 68.76%
   Memory Usage: 48.2 MB less than: 99.70%
   Remarks:
*/

class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), maxReachable = 0, lastPos = 0, i = 0;
        while (i < n && lastPos < (n - 1)) {
            maxReachable = max(maxReachable, i + nums[i]);
            if (i == lastPos) lastPos = maxReachable;
            i++;
        }
        return lastPos == (n - 1);
    }
};