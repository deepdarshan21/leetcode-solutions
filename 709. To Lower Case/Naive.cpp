#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 3 ms faster than: 31.84%
   Memory Usage: 6.1 MB less than: 82.02%
   Remarks:
*/

class Solution {
   public:
    string toLowerCase(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (isupper(s[i])) {
                s[i] = tolower(s[i]);
            }
        }
        return s;
    }
};