#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Recursion

   Edge Cases:

   Time Complexity: O(n) Space: O(logn)
   Status: Accepted
   Runtime: 13 ms faster than: 70.73%
   Memory Usage: 12.2 MB less than: 68.41%
   Remarks:
*/

class Solution {
   public:
    string longestNiceSubstring(string s) {
        if (s.size() < 2) return "";
        set<char> st(s.begin(), s.end());
        for (int i = 0; i < s.size(); i++) {
            if (st.find((char)toupper(s[i])) == st.end() || st.find((char)tolower(s[i])) == st.end()) {
                string s1 = longestNiceSubstring(s.substr(0, i));
                string s2 = longestNiceSubstring(s.substr(i + 1));
                return s1.size() > s2.size() ? s1 : s2;
            }
        }
        return s;
    }
};