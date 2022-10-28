#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Stack
        Whenever meet with any 'c' from start it must have "ab" previous to it

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 11 ms faster than: 93.55%
   Memory Usage: 8.4 MB less than: 31.25%
   Remarks:
*/

class Solution {
   public:
    bool isValid(string s) {
        stack<char> st;
        for (char x : s) {
            if (x == 'c') {
                if (!st.empty() && st.top() == 'b')
                    st.pop();
                else
                    return false;
                if (!st.empty() && st.top() == 'a')
                    st.pop();
                else
                    return false;
            } else
                st.push(x);
        }
        return st.empty();
    }
};