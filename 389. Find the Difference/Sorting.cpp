#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Sorting
        First sort both the strings and then find the unmatched character

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 6.7 MB less than: 24.21%
   Remarks:
*/

class Solution {
   public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != t[i]) {
                return t[i];
            }
        }
        return t[t.size() - 1];
    }
};