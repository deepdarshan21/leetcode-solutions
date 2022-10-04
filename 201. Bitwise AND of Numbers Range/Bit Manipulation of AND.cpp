#include <bits/stdc++.h>
using namespace std;

/*
   Approach: AND bitwise property use

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Acccepted
   Runtime: 8 ms faster than: 93.20%
   Memory Usage: 5.9 MB less than: 77.56%
   Remarks:
*/

class Solution {
   public:
    int rangeBitwiseAnd(int left, int right) {
        if (left == 0 || right == 0) return 0;
        int leftLog = log2(left);
        int rightLog = log2(right);
        if (rightLog != leftLog) return 0;
        int res = right;
        for (int i = left; i < right; i++) {
            res &= i;
        }
        return res;
    }
};