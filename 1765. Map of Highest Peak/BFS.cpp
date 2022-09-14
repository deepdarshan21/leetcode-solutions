#include <bits/stdc++.h>
using namespace std;

/*
   Approach: BFS
        First mark all the water field as height of 0 and store their index in queue;
        Take one by one element from queue and check if possible then increase its neighbour by 1;

   Edge Cases:

   Time Complexity: O(n*m) Space: O(n*m)
   Status: Accepted
   Runtime: 1760 ms faster than: 5.14%
   Memory Usage: 189.8 MB less than: 10.71%
   Remarks:
*/

class Solution {
   public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<int>> res(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j] == 1) {
                    res[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            int val = res[x][y];
            vector<int> temp = {1, 0, -1, 0, 1};
            for (int i = 0; i < 4; i++) {
                if (x + temp[i] >= 0 && x + temp[i] < n && y + temp[i + 1] >= 0 && y + temp[i + 1] < m) {
                    if (res[x + temp[i]][y + temp[i + 1]] == -1) {
                        res[x + temp[i]][y + temp[i + 1]] = val + 1;
                        q.push({x + temp[i], y + temp[i + 1]});
                    }
                }
            }
        }
        return res;
    }
};