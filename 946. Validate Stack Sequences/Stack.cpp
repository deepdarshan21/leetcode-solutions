#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Using Stacks

   Edge Cases:
        1. Element of pushed array didn't traversed completely => return false
        2. Element of popped array didn't traversed completely => if popping possible => return true
                                                                => if popping not possible => return false

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 15 ms faster than: 42.87%
   Memory Usage: 15.4 MB less than: 59.16%
   Remarks:
*/

class Solution {
   public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i, j;
        i = j = 0;
        st.push(pushed[i]);
        i++;
        while (!st.empty() && i < pushed.size() && j < popped.size()) {
            if (!st.empty() && st.top() == popped[j]) {
                st.pop();
                j++;
            }
            if (st.empty() || (!st.empty() && st.top() != popped[j])) {
                st.push(pushed[i]);
                i++;
            }
        }
        if (i < pushed.size()) {
            return false;
        }
        if (j < popped.size()) {
            while (!st.empty()) {
                if (st.top() != popped[j]) {
                    return false;
                }
                st.pop();
                j++;
            }
        }
        if (st.empty()) {
            return true;
        }
        return false;
    }
};