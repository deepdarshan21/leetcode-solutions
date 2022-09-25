#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary to hexadecimal

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 3 ms faster than: 36.22%
   Memory Usage: 6 MB less than: 18.63%
   Remarks:
*/

class Solution {
   public:
    string toHex(int num) {
        if (num == 0) return "0";
        const string HEX = "0123456789abcdef";
        string result = "";
        int count = 0;
        while (num && count++ < 8) {
            result = HEX[num & 0xf] + result;
            num = num >> 4;
        }
        return result;
    }
};