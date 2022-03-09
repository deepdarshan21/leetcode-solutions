#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Using extra space(hash map)

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 5 ms faster than: 22.59%
   Memory Usage: 6.2 MB less than: 42.24%
   Remarks:
*/

class Solution {
   public:
    string freqAlphabets(string s) {
        string res = "";
        int i = 0;
        while (i < s.size()) {
            if ((i + 2) >= s.size()) {
                string temp = "";
                temp.push_back(s[i]);
                res.push_back(96 + stoi(temp));
                i++;
            } else {
                if (s[i + 2] == '#') {
                    string temp = "";
                    temp.push_back(s[i]);
                    temp.push_back(s[i + 1]);
                    res.push_back(96 + stoi(temp));
                    i += 3;
                } else {
                    string temp = "";
                    temp.push_back(s[i]);
                    res.push_back(96 + stoi(temp));
                    i++;
                }
            }
        }
        return res;
    }
};