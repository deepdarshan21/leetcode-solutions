#include <bits/stdc++.h>
using namespace std;

/*
   Approach: String

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n)
   Status: Memory Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    bool isValid(string s) {
        string t = "";
        int n = s.size();
        for (int i = 0; i < n; i++) {
            // cout<<s[i]<<" ";
            if (s[i] == 'a')
                t = t.substr(0, i) + "abc" + t.substr(i, t.size() - i);
            else if (t.size() <= i || t[i] != s[i])
                return false;
            // cout<<t<<endl;
        }
        return t == s;
    }
};