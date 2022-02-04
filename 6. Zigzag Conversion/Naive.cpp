#include <bits/stdc++.h>
using namespace std;

/*
    Approach: Naive


   Edge Cases:


   Time Complexity: O(n) Space: O(1)
        where, n is size of string
*/

class Solution {
   public:
    string convert(string s, int numRows) {
        if (s.size() <= numRows || numRows == 1) {
            return s;
        }
        string ans = "";
        const int gap = numRows * 2 - 2;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < s.size(); j += gap) {
                ans += s[j + i];
                if (i != 0 && i != numRows - 1 && j + gap - i < s.size()) {
                    ans += s[j + gap - i];
                }
            }
        }
        return ans;
    }
};