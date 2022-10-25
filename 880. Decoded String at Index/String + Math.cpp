#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Strng + math

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 6.1 MB less than: 70.00%
   Remarks:
*/

class Solution {
   public:
    string decodeAtIndex(string s, int k) {
        long long size = 0;
        for (char x : s) {
            if (isdigit(x)) {
                size = size * (x - '0');
            } else {
                size++;
            }
        }
        reverse(s.begin(), s.end());
        for (char x : s) {
            k %= size;
            if (k == 0 && !isdigit(x)) return "" + x;
            if (isdigit(x))
                size /= (x - '0');
            else
                size--;
        }
        return "";
    }
};