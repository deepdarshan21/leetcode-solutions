#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Stack


   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Wrong answer
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks: Question statement is not clear
*/

class Solution {
   public:
    int countCollisions(string directions) {
        int res = 0;
        stack<int> st;
        for (char x : directions) {
            if (st.empty() || (st.top() == 'L' && x == 'S') || (st.top() == 'L' && x == 'R')) {
                st.push(x);
            } else {
                if (st.top() == 'R' && x == 'S') {
                    res++;
                    st.pop();
                    st.push(x);
                } else if (st.top() == 'S' && x == 'L') {
                    res++;
                } else if (st.top() == 'R' && x == 'L') {
                    res += 2;
                    st.pop();
                }
            }
        }
        return res;
    }
};