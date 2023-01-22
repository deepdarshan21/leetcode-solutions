#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Math
        Go from target to starting point

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (sx <= tx && sy <= ty) {
            if (sx == tx && sy == ty) return true;
            if (tx == ty) return false;
            if (tx > ty)
                tx -= ty;
            else
                ty -= tx;
        }
        return false;
    }
};