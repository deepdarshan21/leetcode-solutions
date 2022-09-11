#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Greedy
        Simply first make two vector one and then sort them accoding to their efficiency, and then
        make use of priority queue to take top k high speed workers

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(n)
   Status: Accepted
   Runtime: 166 ms faster than: 33.27%
   Memory Usage: 35.3 MB less than: 98.24%
   Remarks:
*/

class Solution {
   public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> eff_speed(n);
        for (int i = 0; i < n; i++) {
            eff_speed[i].first = efficiency[i];
            eff_speed[i].second = speed[i];
        }
        sort(eff_speed.begin(), eff_speed.end(), greater<pair<int, int>>());
        priority_queue<int, vector<int>, greater<int>> top_speeds;
        long long res = 0, total_speed = 0, temp;
        for (int i = 0; i < n; i++) {
            if (top_speeds.size() < k) {
                top_speeds.push(eff_speed[i].second);
                total_speed += eff_speed[i].second;
            } else {
                if (top_speeds.top() < eff_speed[i].second) {
                    total_speed -= top_speeds.top();
                    top_speeds.pop();
                    top_speeds.push(eff_speed[i].second);
                    total_speed += eff_speed[i].second;
                }
            }
            res = max(res, total_speed * eff_speed[i].first);
        }
        return res % 1000000007;
    }
};