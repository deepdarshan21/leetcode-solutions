#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Maths


   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 4 ms faster than: 47.34%
   Memory Usage: 6 MB less than: 38.78%
   Remarks:
*/

class Solution {
   public:
    int titleToNumber(string columnTitle) {
        int pos = 0;
        for (int i = 0; i < columnTitle.size(); i++) {
            pos = pos * 26 + (columnTitle[i] - 64);
        }
        return pos;
    }
};