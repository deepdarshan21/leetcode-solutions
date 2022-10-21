#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Stack based string implementation

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 4 ms faster than: 61.17%
   Memory Usage: 6.1 MB less than: 98.02%
   Remarks:
*/

class Solution {
   public:
    string makeGood(string s) {
        string res = "";
        for (char x : s) {
            if (!res.empty() && ((res.back() + 32) == x || res.back() - 32 == x))
                res.pop_back();
            else
                res.push_back(x);
        }
        return res;
    }
};