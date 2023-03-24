#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Dp(top down)
        In dp array of size 26 we will store the maximum size substring that ends with that char

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 16 ms faster than: 25%
   Memory Usage: 8.2 MB less than: 13.81%
   Remarks:
*/

class Solution {
   public:
    int findSubstringInWraproundString(string s) {
        int n = s.size();

        function<char(char)> nextChar = [&](char ch) {
            if (ch == 'z') return 'a';
            return char(ch + 1);
        };

        unordered_map<char, int> dp;
        dp[s[0]] = 1;
        int tmp = 1;

        for (int i = 1; i < n; i++) {
            if (nextChar(s[i - 1]) == s[i])
                tmp++;
            else
                tmp = 1;
            dp[s[i]] = max(dp[s[i - 1]], tmp);
        }

        int res = 0;
        for (auto it : dp) res += it.second;
        return res;
    }
};