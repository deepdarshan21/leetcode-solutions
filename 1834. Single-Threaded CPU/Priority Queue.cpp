#include <bits/stdc++.h>
using namespace std;

/*
   Approach: First sort and then push them in min-heap

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(n)
   Status: Accepted
   Runtime: 727 ms faster than: 78.4%
   Memory Usage: 150.7 MB less than: 30.42%
   Remarks:
*/

class Solution {
   public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<vector<int>> sortedTasks;
        for (int i = 0; i < tasks.size(); ++i) {
            sortedTasks.push_back({tasks[i][0], tasks[i][1], i});
        }
        sort(sortedTasks.begin(), sortedTasks.end());
        int idx = 0;
        long long time = 0;
        while (!pq.empty() || idx < n) {
            if (pq.empty() && time < sortedTasks[idx][0]) {
                time = sortedTasks[idx][0];
            }
            while (idx < n && time >= sortedTasks[idx][0]) {
                pq.push({sortedTasks[idx][1], sortedTasks[idx][2]});
                idx++;
            }
            auto [processTime, index] = pq.top();
            pq.pop();
            res.push_back(index);
            time += processTime;
        }
        return res;
    }
};