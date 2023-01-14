#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Priority Queue(BFS)

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 183 ms faster than: 16.97%
   Memory Usage: 30.9 MB less than: 8.16%
   Remarks:
*/

class Solution {
   public:
    int nthUglyNumber(int n) {
        priority_queue<int, vector<int>, greater<int>> pq;
        set<int> vis;
        pq.push(1);
        vis.insert(1);
        int counter = 0;
        while (!pq.empty()) {
            counter++;
            int tmp = pq.top();
            pq.pop();
            if (counter == n) return tmp;
            if (INT_MAX / 2 >= tmp && vis.find(tmp * 2) == vis.end()) {
                pq.push(tmp * 2);
                vis.insert(tmp * 2);
            }
            if (INT_MAX / 3 >= tmp && vis.find(tmp * 3) == vis.end()) {
                pq.push(tmp * 3);
                vis.insert(tmp * 3);
            }
            if (INT_MAX / 5 >= tmp && vis.find(tmp * 5) == vis.end()) {
                pq.push(tmp * 5);
                vis.insert(tmp * 5);
            }
        }
        return -1;
    }
};