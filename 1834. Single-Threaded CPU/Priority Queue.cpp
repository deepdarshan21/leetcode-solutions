#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int time = 0, added = 0;
        while (!pq.empty() || added < n) {
            for (int i = 0; i < n; i++) {
                if (time >= tasks[i][0]) {
                    pq.push({tasks[i][1], i});
                    tasks[i][0] = INT_MAX;
                    added++;
                }
            }
            if (!pq.empty()) {
                int tmp = pq.top().first;
                res.push_back(pq.top().second);
                pq.pop();
                time += tmp;
            } else {
                time++;
            }
        }
        return res;
    }
};