#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Using extra space(hash map)

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 6.4 MB less than: 18.94%
   Remarks:
*/

class Solution {
   public:
    string freqAlphabets(string s) {
        string res = "";
        unordered_map<int, char> mp;
        for (int i = 1; i <= 26; i++) {
            mp[i] = 96 + i;
        }
        int i = 0;
        while (i < s.size()) {
            if ((i + 2) >= s.size()) {
                string temp = "";
                temp.push_back(s[i]);
                res.push_back(mp[stoi(temp)]);
                i++;
            } else {
                if (s[i + 2] == '#') {
                    string temp = "";
                    temp.push_back(s[i]);
                    temp.push_back(s[i + 1]);
                    res.push_back(mp[stoi(temp)]);
                    i += 3;
                } else {
                    string temp = "";
                    temp.push_back(s[i]);
                    res.push_back(mp[stoi(temp)]);
                    i++;
                }
            }
        }
        return res;
    }
};