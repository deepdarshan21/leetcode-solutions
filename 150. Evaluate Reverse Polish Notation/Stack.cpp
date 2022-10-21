#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Stack

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 25 ms faster than: 41.89%
   Memory Usage: 12.2 MB less than: 14.54%
   Remarks:
*/

class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        int num1, num2;
        for (string token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                num1 = st.top();
                st.pop();
                num2 = st.top();
                st.pop();
            } else {
                st.push(stoi(token));
                continue;
            }
            if (token == "+")
                st.push((long long)num1 + num2);
            else if (token == "-")
                st.push((long long)num2 - num1);
            else if (token == "*")
                st.push(num1 * num2);
            else if (token == "/")
                st.push(num2 / num1);
        }
        return st.top();
    }
};