#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Greedy

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Accepted
   Runtime: 210 ms faster than: 69%
   Memory Usage: 76.4 MB less than: 76.68%
   Remarks:
*/

class Solution {
   public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        int res = 0;
        sort(costs.begin(), costs.end());
        for (int i = 0; i < n; i++) {
            if (coins < costs[i]) break;
            coins -= costs[i];
            res++;
        }
        return res;
    }
};