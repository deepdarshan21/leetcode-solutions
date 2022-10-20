#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Stack

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 2 ms faster than: 64.24%
   Memory Usage: 6.5 MB less than: 6.23%
   Remarks:
*/

class Solution {
   public:
    bool backspaceCompare(string s, string t) {
        stack<char> sts, stt;
        for (char x : s) {
            if (x != '#') {
                sts.push(x);
            } else {
                if (!sts.empty()) sts.pop();
            }
        }
        for (char x : t) {
            if (x != '#') {
                stt.push(x);
            } else {
                if (!stt.empty()) stt.pop();
            }
        }
        while (!sts.empty() && !stt.empty()) {
            if (sts.top() != stt.top()) return false;
            sts.pop();
            stt.pop();
        }
        if (sts.empty() && stt.empty()) return true;
        return false;
    }
};