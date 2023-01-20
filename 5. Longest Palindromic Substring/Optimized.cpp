#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Two Pointer Type

   Edge Cases:

   Time Complexity: O(n^2) Space: O(1)
   Status: Accepted
   Runtime: 15 ms faster than: 84.99%
   Memory Usage: 6.8 MB less than: 90.41%
   Remarks:
*/

class Solution {
   public:
    string longestPalindrome(string s) {
        int n = s.size();
        int res = 0;
        int l, r, tmp = 0;
        string ans = "";
        for (int i = 0; i < n; i++) {
            l = i;
            r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                int len = r - l + 1;
                if (len > res) {
                    tmp = l;
                    res = len;
                }
                l--;
                r++;
            }
            l = i;
            r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                int len = r - l + 1;
                if (len > res) {
                    tmp = l;
                    res = len;
                }
                l--;
                r++;
            }
        }
        ans = s.substr(tmp, res);
        return ans;
    }
};