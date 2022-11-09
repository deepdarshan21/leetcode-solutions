#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Greedy
        Total diff must be greater then equal to zero for exiting the answer

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 89 ms faster than: 92.34%
   Memory Usage: 69.4 MB less than: 88.72%
   Remarks:
*/

class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), res = 0, total = 0, curr = 0;
        for (int i = 0; i < n; i++) {
            int temp = gas[i] - cost[i];
            total += temp;
            curr += temp;
            if (curr < 0) {
                res = i + 1;
                curr = 0;
            }
        }
        if (total > 0) return res;
        return -1;
    }
};