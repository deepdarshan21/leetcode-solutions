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
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        queue<int> q, tmpQ;
        int jumps;
        unordered_map<int, vector<int>> store;
        for (int i = 0; i < n; i++) {
            store[arr[i]].push_back(i);
        }
        q.push(n - 1);
        jumps = 0;
        while (!q.empty()) {
            while (!q.empty()) {
                int i = q.front();
                q.pop();
                if (i == 0) return jumps;
                if (i + 1 < n) tmpQ.push(i + 1);
                if (i - 1 >= 0) tmpQ.push(i - 1);
                for (int j : store[arr[i]]) {
                    if (j != i) tmpQ.push(j);
                }
            }
            jumps++;
            swap(q, tmpQ);
        }
        return jumps;
    }
};