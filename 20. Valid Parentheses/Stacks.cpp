#include <bits/stdc++.h>
using namespace std;

/*
    Approach: Using Stacks
       Stacks helps me in finding what kind of bracket is lastly used

   Edge Cases:
       1. At last store stack has some opening brackets remaining
       2. String has only closing bracket

   Time Complexity: O(n) Space: O(1)
*/

class Solution {
   public:
    bool isValid(string s) {
        stack<char> store;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                store.push(s[i]);
            } else if (s[i] == ')') {
                if (!store.empty() && store.top() == '(') {
                    store.pop();
                } else {
                    return false;
                }
            } else if (s[i] == ']') {
                if (!store.empty() && store.top() == '[') {
                    store.pop();
                } else {
                    return false;
                }
            } else if (s[i] == '}') {
                if (!store.empty() && store.top() == '{') {
                    store.pop();
                } else {
                    return false;
                }
            }
        }
        if (!store.empty()) {
            return false;
        }
        return true;
    }
};