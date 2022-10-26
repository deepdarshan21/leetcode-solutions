#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Math (Sum of number 1 to n)

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 69 ms faster than: 34.88%
   Memory Usage: 11.6 MB less than: 35.35%
   Remarks:
*/

class Solution {
   public:
    int countHomogenous(string s) {
        int res = 0, temp = 0, n = s.size(), mod = 1e9 + 7;
        for (int i = 1; i < n; i++) {
            res = (res + (i - temp)) % mod;
            if (s[i] != s[i - 1]) temp = i;
        }
        res = (res + (n - temp)) % mod;
        return res;
    }
};