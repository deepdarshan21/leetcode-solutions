#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Sliding Window

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 42 ms faster than: 45.23%
   Memory Usage: 7.7 MB less than: 68.10%
   Remarks:
*/

class Solution {
   public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if (n < m) return "";
        unordered_map<char, int> mp;
        for (char x : t) mp[x]++;
        int minLength = INT_MAX, startAt = -1;
        int left = 0, right = 0;
        while (right < n) {
            if (mp.find(s[right]) != mp.end()) {
                mp[s[right]]--;
                if (mp[s[right]] >= 0) m--;
            }
            while (m == 0) {
                int len = right - left + 1;
                if (len < minLength) {
                    minLength = len;
                    startAt = left;
                }
                if (mp.find(s[left]) != mp.end()) {
                    if (mp[s[left]] == 0) m++;
                    mp[s[left]]++;
                }
                left++;
            }
            right++;
        }
        string res = "";
        if (startAt == -1) return res;
        for (int i = startAt; i < (startAt + minLength); i++) res += s[i];
        return res;
    }
};