#include <bits/stdc++.h>
using namespace std;

/*
   Approach: String Manipulation

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 377 ms faster than: 5.0%
   Memory Usage: 25.9 MB less than: 63.46%
   Remarks:
*/

class Solution {
   public:
    string removeStars(string s) {
        string res = "";
        for (char x : s) {
            if (x == '*') {
                if (!res.empty()) res.pop_back();
            } else
                res.push_back(x);
        }
        return res;
    }
};