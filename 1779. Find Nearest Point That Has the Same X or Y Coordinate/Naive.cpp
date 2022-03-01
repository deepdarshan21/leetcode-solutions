#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 204 ms faster than: 61.00%
   Memory Usage: 59.3 MB less than: 75.13%
   Remarks:
*/

class Solution {
   public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int minDistance = INT_MAX, index, temp;
        for (int i = 0; i < points.size(); i++) {
            if (points[i][0] == x || points[i][1] == y) {
                temp = abs(points[i][0] - x) + abs(points[i][1] - y);
                if (temp < minDistance) {
                    minDistance = temp;
                    index = i;
                }
            }
        }
        if (INT_MAX == minDistance) {
            return -1;
        }
        return index;
    }
};