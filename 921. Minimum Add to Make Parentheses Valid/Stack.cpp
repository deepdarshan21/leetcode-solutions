#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Stack

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 6.4 MB less than: 25.18%
   Remarks:
*/

class Solution {
   public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for (char x : s) {
            if (x == ')' && !st.empty() && st.top() == '(')
                st.pop();
            else
                st.push(x);
        }
        return st.size();
    }
};