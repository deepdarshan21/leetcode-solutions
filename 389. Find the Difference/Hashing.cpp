#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Hashing
        Store the frequency of each chracter in string "t" in unordered map and then decrease the
        frequency of characters that are pressent in string "s".

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 4 ms faster than: 62.06%
   Memory Usage: 6.7 MB less than: 24.21%
   Remarks:
*/

class Solution {
   public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> mp;
        for (int i = 0; i < t.size(); i++) {
            mp[t[i]]++;
        }
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]--;
        }
        for (auto temp : mp) {
            if (temp.second == 1) {
                return temp.first;
            }
        }
        return ' ';
    }
};