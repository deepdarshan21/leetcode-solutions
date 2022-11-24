#include <bits/stdc++.h>
using namespace std;

/*
   Approach: BFS

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 22 ms faster than: 34%
   Memory Usage: 14.5 MB less than: 12%
   Remarks:
*/

class Solution {
   public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, false));
        q.push({sr, sc});
        visited[sr][sc] = true;
        int startColor = image[sr][sc];
        while (!q.empty()) {
            pair<int, int> temp = q.front();
            q.pop();
            if (temp.second + 1 < m && !visited[temp.first][temp.second + 1] && image[temp.first][temp.second + 1] == startColor) {
                q.push({temp.first, temp.second + 1});
            }
            if (temp.second - 1 >= 0 && !visited[temp.first][temp.second - 1] && image[temp.first][temp.second - 1] == startColor) {
                q.push({temp.first, temp.second - 1});
            }
            if (temp.first + 1 < n && !visited[temp.first + 1][temp.second] && image[temp.first + 1][temp.second] == startColor) {
                q.push({temp.first + 1, temp.second});
            }
            if (temp.first - 1 >= 0 && !visited[temp.first - 1][temp.second] && image[temp.first - 1][temp.second] == startColor) {
                q.push({temp.first - 1, temp.second});
            }
            image[temp.first][temp.second] = color;
            visited[temp.first][temp.second] = true;
        }
        return image;
    }
};