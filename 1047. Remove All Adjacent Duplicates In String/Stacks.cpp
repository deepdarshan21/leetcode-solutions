#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Stack

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 73 ms faster than: 32.49%
   Memory Usage: 11.3 MB less than: 44.36%
   Remarks:
*/

class Solution {
   public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (char x : s) {
            if (!st.empty() && st.top() == x)
                st.pop();
            else
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