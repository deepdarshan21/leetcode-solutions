#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Math

   Edge Cases:

   Time Complexity: O(logn) Space: O(1)
   Status:Accepted
   Runtime: 2 ms faster than: 50%
   Memory Usage: 6 MB less than: 43.88%
   Remarks:
*/

class Solution {
   public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (sx <= tx && sy <= ty) {
            if (sx == tx && sy == ty) return true;
            if (tx == ty) return false;
            if (tx > ty) {
                if (tx == 0)
                    tx = ty;
                else if (((tx - sx) / ty) == 0)
                    tx -= ty;
                else
                    tx -= ((tx - sx) / ty) * ty;
            } else {
                if (ty == 0)
                    ty = tx;
                else if (((ty - sy) / tx) == 0)
                    ty -= tx;
                else
                    ty -= ((ty - sy) / tx) * tx;
            }
        }
        return false;
    }
};