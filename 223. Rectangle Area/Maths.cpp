#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Math

   Edge Cases:

   Time Complexity: O(1) Space: O(1)
   Status: Accepted
   Runtime: 8 ms faster than: 87.10%
   Memory Usage: 5.9 MB less than: 75.31%
   Remarks:
*/

class Solution {
   public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int res = 0;
        res += abs(ax2 - ax1) * abs(ay2 - ay1);
        res += abs(bx2 - bx1) * abs(by2 - by1);
        int x1, x2, y1, y2;
        x1 = max(ax1, bx1);
        x2 = min(ax2, bx2);
        y1 = max(ay1, by1);
        y2 = min(ay2, by2);
        int temp = (x2 - x1) * (y2 - y1);
        if ((x2 - x1) <= 0 || (y2 - y1) <= 0) return res;
        if (temp > 0) res -= temp;
        return res;
    }
};