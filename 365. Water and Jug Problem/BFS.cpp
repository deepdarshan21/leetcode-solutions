#include <bits/stdc++.h>
using namespace std;

/*
   Approach: BFS

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 526 ms faster than: 15.21%
   Memory Usage: 68 MB less than: 15.23%
   Remarks:
*/

class Solution {
   public:
    bool canMeasureWater(int x, int y, int t) {
        if ((x + y) < t) return false;
        vector<int> dirs = {x, -x, y, -y};
        queue<int> q;
        set<int> vis;
        q.push(0);
        vis.insert(0);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int dir : dirs) {
                int total = curr + dir;
                if (total == z) return true;
                if (total < 0 || total > (x + y) || vis.count(total)) continue;
                q.push(total);
                vis.insert(total);
            }
        }
        return false;
    }
};