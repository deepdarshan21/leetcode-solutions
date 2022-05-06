#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force(Intutive)

   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    string removeDuplicates(string s, int k) {
        bool flag = true;
        while (flag) {
            int i = 0;
            flag = false;
            while (i < s.size()) {
                if (s[i] == s[i + 1]) {
                    int j;
                    for (j = 2; j < k; j++) {
                        if (s[i] != s[i + j]) {
                            break;
                        }
                    }
                    if (j == k) {
                        flag = true;
                        s.erase(s.begin() + i, s.begin() + i + k);
                        i--;
                    }
                }
                i++;
            }
        }
        return s;
    }
};