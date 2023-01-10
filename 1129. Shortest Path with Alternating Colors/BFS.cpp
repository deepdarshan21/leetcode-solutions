#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status:
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> res(n, INT_MAX);
        vector<bool> visitedRed(n, false), visitedBlue(n, false);
        unordered_map<int, vector<int>> red, blue;
        for (int i = 0; i < redEdges.size(); i++) red[redEdges[i][0]].push_back(redEdges[i][1]);
        for (int i = 0; i < blueEdges.size(); i++) blue[blueEdges[i][0]].push_back(blueEdges[i][1]);
        queue<int> redQ, blueQ;
        res[0] = 0;
        redQ.push(0);
        blueQ.push(0);
        int path = 0;
        while (!redQ.empty() && !blueQ.empty()) {
            path++;
            queue<int> tmpRed, tmpBlue;
            while (!redQ.empty()) {
                int tmp = redQ.front();
                redQ.pop();
                for (int num : redEdges[tmp]) tmpBlue.push(num);
                if (res[tmp] > path) res[tmp] = path;
            }
            while (!blueQ.empty()) {
                int tmp = blueQ.front();
                blueQ.pop();
                for (int num : redEdges[tmp]) tmpRed.push(num);
                if (res[tmp] > path) res[tmp] = path;
            }
            redQ = tmpRed;
            blueQ = tmpBlue;
        }
        if (int i = 0; i < n; i++) {
            if (res[i] == INT_MAX) res[i] = -1;
        }
        return res;
    }
};