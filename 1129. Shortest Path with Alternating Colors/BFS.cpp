#include <bits/stdc++.h>
using namespace std;

/*
   Approach: BFS

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 17 ms faster than: 92.68%
   Memory Usage: 16.5 MB less than: 11.48%
   Remarks:
*/

class Solution {
   public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> res(n, INT_MAX);
        unordered_map<int, vector<int>> red, blue;
        for (int i = 0; i < redEdges.size(); i++) red[redEdges[i][0]].push_back(redEdges[i][1]);
        for (int i = 0; i < blueEdges.size(); i++) blue[blueEdges[i][0]].push_back(blueEdges[i][1]);
        vector<bool> visRed(n, false), visBlue(n, false);
        queue<int> redQ, blueQ;
        res[0] = 0;
        redQ.push(0);
        blueQ.push(0);
        int path = 0;
        while (!redQ.empty() || !blueQ.empty()) {
            path++;
            queue<int> tmpRed, tmpBlue;
            while (!redQ.empty()) {
                int tmp = redQ.front();
                redQ.pop();
                for (int num : red[tmp]) {
                    if (visRed[num]) continue;
                    visRed[num] = true;
                    tmpBlue.push(num);
                    if (res[num] > path) res[num] = path;
                }
            }
            while (!blueQ.empty()) {
                int tmp = blueQ.front();
                blueQ.pop();
                for (int num : blue[tmp]) {
                    if (visBlue[num]) continue;
                    visBlue[num] = true;
                    tmpRed.push(num);
                    if (res[num] > path) res[num] = path;
                }
            }
            redQ = tmpRed;
            blueQ = tmpBlue;
        }
        for (int i = 0; i < n; i++) {
            if (res[i] == INT_MAX) res[i] = -1;
        }
        return res;
    }
};