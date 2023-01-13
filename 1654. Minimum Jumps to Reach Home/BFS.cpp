#include <bits/stdc++.h>
using namespace std;

/*
   Approach: BFS

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 145 ms faster than: 35.29%
   Memory Usage: 32.2 MB less than: 42.93%
   Remarks:
*/

class Solution {
   public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        set<int> block(forbidden.begin(), forbidden.end());
        set<pair<int, bool>> vis;
        queue<pair<int, pair<bool, int>>> q;
        // {pos, backallowed}
        int upper = 10000;
        q.push({0, {false, 0}});
        vis.insert({0, false});
        while (!q.empty()) {
            int currPos = q.front().first;
            int backAllowed = q.front().second.first;
            int steps = q.front().second.second;
            q.pop();
            if (currPos == x) return steps;
            int forward = currPos + a;
            if (forward <= upper && block.find(forward) == block.end() && !vis.count({forward, true})) {
                if (forward == x) return steps + 1;
                q.push({forward, {true, steps + 1}});
                vis.insert({forward, true});
            }
            if (backAllowed) {
                int previous = currPos - b;
                if (previous >= 0 && block.find(previous) == block.end() && !vis.count({previous, false})) {
                    if (previous == x) return steps + 1;
                    q.push({previous, {false, steps + 1}});
                    vis.insert({previous, false});
                }
            }
        }
        return -1;
    }
};