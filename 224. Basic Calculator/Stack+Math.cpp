#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Stack

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 9 ms faster than: 87%
   Memory Usage: 8.1 MB less than: 72%
   Remarks:
*/

class Solution {
   public:
    int calculate(string s) {
        stack<int> st;
        int res = 0, curr = 0, sign = 1;
        for (char x : s) {
            if (x == ' ') continue;
            if (isdigit(x)) curr = curr * 10 + (x - '0');
            if (x == '+') {
                res += curr * sign;
                curr = 0;
                sign = 1;
            }
            if (x == '-') {
                res += curr * sign;
                sign = -1;
                curr = 0;
            }
            if (x == '(') {
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            }
            if (x == ')') {
                res += curr * sign;
                curr = 0;
                res = res * st.top();
                st.pop();
                res += st.top();
                st.pop();
            }
        }
        res += curr * sign;

        return res;
    }
};