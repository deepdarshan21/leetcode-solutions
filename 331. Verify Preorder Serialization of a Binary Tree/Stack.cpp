#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Stack

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 37 ms faster than: 6.70%
   Memory Usage: 10.9 MB less than: 7.60%
   Remarks:
*/

class Solution {
   public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        string curr;
        stack<string> st;
        while (getline(ss, curr, ',')) {
            st.push(curr);
            while (st.size() >= 3) {
                string temp1, temp2;
                temp1 = st.top();
                st.pop();
                temp2 = st.top();
                st.pop();
                if (temp1 == "#" and temp2 == "#" and st.top() != "#") {
                    st.pop();
                    st.push("#");
                } else {
                    st.push(temp2);
                    st.push(temp1);
                }
            }
        }
        return st.empty();
    }
};