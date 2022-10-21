#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Solution inspired by stack implementation

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 6.3 MB less than: 57.36%
   Remarks:
*/

class Solution {
   public:
    int maxDepth(string s) {
        int res = 0, temp = 0;
        for (char x : s) {
            if (x == '(') {
                temp++;
                res = max(res, temp);
            } else if (x == ')')
                temp--;
        }
        return res;
    }
};