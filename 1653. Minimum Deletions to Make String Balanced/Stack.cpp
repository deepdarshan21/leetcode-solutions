#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Wrong Answer
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int minimumDeletions(string s) {
        stack<char> st1, st2;
        int temp1 = 0, temp2 = 0;
        for (char x : s) {
            while (x == 'a' && !st1.empty() && st1.top() == 'b') {
                temp1++;
                st1.pop();
            }
            st1.push(x);
            if (!st2.empty() && st2.top() == 'b' && x == 'a') {
                temp2++;
                continue;
            }
            st2.push(x);
        }
        return min(temp1, temp2);
    }
};