#include <bits/stdc++.h>
using namespace std;

/*
   Approach: stack

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 6 ms faster than: 59.97%
   Memory Usage: 6.8 MB less than: 18.90%
   Remarks:
*/

class Solution {
   public:
    string removeOuterParentheses(string s) {
        string res = "";
        stack<char> st;
        for (char x : s) {
            if (!st.empty() && x == ')') {
                if (st.size() > 1) res += x;
                st.pop();
            } else {
                st.push(x);
                if (st.size() > 1) res += x;
            }
        }
        return res;
    }
};