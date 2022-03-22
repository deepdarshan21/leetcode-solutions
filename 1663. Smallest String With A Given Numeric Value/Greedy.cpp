#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: TLE
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    string getSmallestString(int n, int k) {
        string s = "";
        n = n * 26;
        while (k > 0) {
            if (n - k > 26) {
                s.push_back('a');
                n -= 26;
                k--;
            } else {
                s.push_back(96 + 26 - (n - k));
                k -= 26 - (n - k);
                break;
            }
        }
        while (k > 0) {
            s.push_back('z');
        }
        return s;
    }
};