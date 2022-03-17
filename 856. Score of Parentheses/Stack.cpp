#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Stack
        Use stack to memorise the score till now
        If choosen element is "(" then push 0 into stack
        If choosen element is ")" then pop the last element and update the 'top' of stack

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 6.1 MB less than: 83.25%
   Remarks:
*/

class Solution {
   public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for (auto itr : s) {
            if (itr == '(') {
                st.push(0);
            } else {
                int temp = st.top();
                st.pop();
                st.top() += max(temp * 2, 1);
            }
        }
        return st.top();
    }
};