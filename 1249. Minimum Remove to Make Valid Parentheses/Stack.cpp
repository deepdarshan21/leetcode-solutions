#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Stack

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 51 ms faster than: 18%
   Memory Usage: 11.1 MB less than: 60%
   Remarks:
*/

class Solution {
   public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> check;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                check.push({'(', i});
            } else if (s[i] == ')') {
                if (!check.empty() && check.top().first == '(') {
                    check.pop();
                } else {
                    s.erase(s.begin() + i);
                    i--;
                }
            }
        }
        while (!check.empty()) {
            s.erase(s.begin() + check.top().second);
            check.pop();
        }
        return s;
    }
};