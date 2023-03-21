#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Math

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 166 ms faster than: 79.49%
   Memory Usage: 107.5 MB less than: 54.45%
   Remarks:
*/

class Solution {
   public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;
        int currCnt = 0;
        for (int num : nums) {
            if (num != 0)
                currCnt = 0;
            else {
                currCnt++;
                res += currCnt;
            }
        }
        return res;
    }
};