#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Maths


   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Accepted
   Runtime: 4 ms faster than: 47.34%
   Memory Usage: 6.1 MB less than: 28.55%
   Remarks: Try without revesing the given string
*/

class Solution {
   public:
    int titleToNumber(string columnTitle) {
        int pos = 0;
        reverse(columnTitle.begin(), columnTitle.end());
        for (int i = 0; i < columnTitle.size(); i++) {
            pos += (columnTitle[i] - 64) * pow(26, i);
        }
        return pos;
    }
};