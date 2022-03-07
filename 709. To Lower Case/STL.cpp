#include <bits/stdc++.h>
using namespace std;

/*
   Approach: STL transform function


   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accpeted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 6.2 MB less than: 8.88%
   Remarks:
*/

class Solution {
   public:
    string toLowerCase(string s) {
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        return s;
    }
};