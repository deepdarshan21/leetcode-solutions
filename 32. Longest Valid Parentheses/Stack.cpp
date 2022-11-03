#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Stack

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 3 ms faster than: 94.88%
   Memory Usage: 7.4 MB less than: 41.82%
   Remarks:
*/

class Solution {
   public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int n = s.size(), res = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == ')') {
                if (!st.empty() && st.top() != -1 && s[st.top()] == '(') {
                    st.pop();
                    if (st.empty()) st.push(-1);
                    res = max(res, i - st.top());
                    continue;
                }
            }
            st.push(i);
        }
        return res;
    }
};