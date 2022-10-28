#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status:
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
            if (s[i] == 'a')
                t = t.substr(i) + "abc" + t.substr(i, n - i);
            else if (t.size() >= i)
                return false;
        }
        return true;
    }
};