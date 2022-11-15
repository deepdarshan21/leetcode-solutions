#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Greedy(Sorting)

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Accepted
   Runtime: 991 ms faster than: 53.59%
   Memory Usage: 89.7 MB less than: 93.11%
   Remarks:
*/

class Solution {
   public:
    int findMinArrowShots(vector<vector<int>> &points) {
        if (points.size() == 0) return 0;
        sort(points.begin(), points.end(), [](vector<int> &first, vector<int> &second) {
            return first[1] < second[1];
        });
        int last = 0, res = 0, n = points.size();
        for (int i = 1; i < n; i++) {
            if (points[last][1] >= points[i][0])
                res++;
            else
                last = i;
        }
        return n - res;
    }
};