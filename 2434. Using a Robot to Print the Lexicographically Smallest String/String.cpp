#include <bits/stdc++.h>
using namespace std;

/*
   Approach: String

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 229 ms faster than: 72.27%
   Memory Usage: 34.4 MB less than: 30.89%
   Remarks:
*/

class Solution {
   public:
    string robotWithString(string s) {
        int n = s.size();
        string temp = s;
        for (int i = n - 2; i >= 0; i--) {
            temp[i] = min(temp[i + 1], s[i]);
        }
        string t = "", res = "";
        for (int i = 0; i < n; i++) {
            while (!t.empty() && t.back() <= temp[i]) {
                res += t.back();
                t.pop_back();
            }
            t.push_back(s[i]);
        }
        while (!t.empty()) {
            res += t.back();
            t.pop_back();
        }
        return res;
    }
};