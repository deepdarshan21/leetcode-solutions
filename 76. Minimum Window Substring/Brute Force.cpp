#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force

   Edge Cases:

   Time Complexity: O(n^3) Space: O(1)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        string temp;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < (n - i + 1); j++) {
                temp = s.substr(j, i);
                if (isSubString) return temp;
            }
        }
        return "";
    }
    bool isSubString(string s, string t) {
        unordered_map<char, int> mp;
        for (char x : s) mp[x]++;
        for (char x : t) {
            if (mp[x] == 0) return false;
            mp[x]--;
        }
        return true;
    }
};