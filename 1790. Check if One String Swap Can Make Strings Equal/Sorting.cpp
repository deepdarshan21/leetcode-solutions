#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Sorting

   Edge Cases:

   Time Complexity: O(nLogn) Space: O(1)
   Status: Accepted
   Runtime:6 ms faster than: 17.20%
   Memory Usage: 6.1 MB less than: 90.57%
   Remarks:
*/

class Solution {
   public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1.compare(s2) == 0) {
            return true;
        }
        int diff = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                diff++;
            }
            if (diff > 2) {
                return false;
            }
        }
        if (diff == 2) {
            sort(s1.begin(), s1.end());
            sort(s2.begin(), s2.end());
            if (s1.compare(s2) != 0) {
                return false;
            }
        }
        return true;
    }
};