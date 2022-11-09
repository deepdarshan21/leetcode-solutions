#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Wrong Answer
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks: [5,8,2,8]
            [6,5,6,6]
*/

class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<pair<int, int>> gasCost;
        int n = gas.size();
        for (int i = 0; i < n; i++) gasCost.push_back({gas[i], cost[i]});
        sort(gasCost.begin(), gasCost.end(), [&](pair<int, int> p1, pair<int, int> p2) {
            return p1.first / (p1.second * 1.0) > p2.first / (p2.second * 1.0);
        });
        int temp = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (gas[i] == gasCost[0].first && cost[i] == gasCost[0].second) {
                res = i;
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            temp += gas[(i + res) % n] - cost[(i + res) % n];
            // cout<<temp<<endl;
            if (temp < 0) return -1;
        }
        return res;
    }
};