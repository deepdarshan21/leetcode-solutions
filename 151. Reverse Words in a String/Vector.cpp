#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Vector of string

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 13 ms faster than: 50.87%
   Memory Usage: 8.1 MB less than: 44.99%
   Remarks:
*/

class Solution {
   public:
    string reverseWords(string s) {
        vector<string> store;
        string temp = "";
        for (char x : s) {
            if (x == ' ') {
                if (temp != "") store.push_back(temp);
                temp = "";
            } else {
                temp += x;
            }
        }
        reverse(store.begin(), store.end());
        string res = "";
        for (string st : store) {
            res += st;
            res += " ";
        }
        res.pop_back();
        return res;
    }
};