#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Stack

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 3 ms faster than: 64.19%
   Memory Usage: 6.4 MB less than: 52.89%
   Remarks:
*/

class Solution {
   public:
    string reverseParentheses(string s) {
        stack<char> st;
        for (char x : s) {
            if (x == ')') {
                string temp = "";
                while (!st.empty() && st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }
                st.pop();
                reverse(temp.begin(), temp.end());
                while (temp.size() > 0) {
                    st.push(temp.back());
                    temp.pop_back();
                }
            } else
                st.push(x);
        }
        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};