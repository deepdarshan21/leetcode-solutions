#include <bits/stdc++.h>
using namespace std;

/*
   Approach: brute force, math
        first find slope and c and then cont count max for a point

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n)
   Status: Accepted
   Runtime: 25 ms faster than: 97.5%
   Memory Usage: 14.9 MB less than: 49.49%
   Remarks:
*/

class Solution {
   public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 1, n = points.size();
        auto calc = [&](int x1, int y1, int x2, int y2) {
            if ((x2 - x1) == 0) return make_pair(INT_MAX * 1.0, x1 * 1.0);
            double slope = (y2 - y1) / ((x2 - x1) * 1.0);
            double c = y1 - slope * x1;
            return make_pair(slope, c);
        };
        for (int i = 0; i < n; i++) {
            int counter = 0;
            pair<double, double> slopeAndC;
            map<pair<double, double>, int> mp;
            for (int j = i + 1; j < n; j++) {
                slopeAndC = calc(points[i][0], points[i][1], points[j][0], points[j][1]);
                mp[slopeAndC]++;
            }
            int tmp = 0;
            for (auto itr : mp) tmp = max(tmp, itr.second + 1);
            res = max(res, tmp);
        }
        return res;
    }
};