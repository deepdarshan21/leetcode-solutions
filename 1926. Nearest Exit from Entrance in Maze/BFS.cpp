#include <bits/stdc++.h>
using namespace std;

/*
   Approach: BFS

   Edge Cases:

   Time Complexity: O(n*m) Space: O(n)
   Status: Accepted
   Runtime: 146 ms faster than: 83.28%
   Memory Usage: 33.8 MB less than: 25.78%
   Remarks:
*/

class Solution {
   public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size(), m = maze[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, int>> q, qTemp;
        q.push({entrance[0], entrance[1]});
        int steps = 0;
        while (!q.empty()) {
            steps++;
            while (!q.empty()) {
                int i = q.front().first, j = q.front().second;
                // cout<<i<<" "<<j<<endl;
                q.pop();
                if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || maze[i][j] == '+') continue;
                if (steps != 1 && (i == 0 || j == 0 || i == (n - 1) || j == (m - 1))) return steps - 1;
                vis[i][j] = true;
                // cout<<"pushing..."<<endl;
                if (i < (n - 1) && maze[i + 1][j] != '+') qTemp.push({i + 1, j});
                if (i > 0 && maze[i - 1][j] != '+') qTemp.push({i - 1, j});
                if (j < (m - 1) && maze[i][j + 1] != '+') qTemp.push({i, j + 1});
                if (j > 0 && maze[i][j - 1] != '+') qTemp.push({i, j - 1});
            }
            swap(qTemp, q);
        }
        return -1;
    }
};