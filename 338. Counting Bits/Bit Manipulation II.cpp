#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Bit Manipulation
        If x/2=y => number of 1's in "x" - number of 1's in "y" can be (0 or 1).
        ~ if x is even => number of 1's in x - number of 1's in y is 0(if y is xx1xx then x is xx1xx0)
        ~ if x is odd => number of 1's in x - number of 1's in y is 1(if y is xx1xx0 then x is xx1xxx1)

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 7 ms faster than: 62.32%
   Memory Usage: 8.5 MB less than: 21.58%
   Remarks:
*/

class Solution {
   public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                ans.push_back(ans[i / 2]);
            } else {
                ans.push_back(ans[i / 2] + 1);
            }
        }
        return ans;
    }
};