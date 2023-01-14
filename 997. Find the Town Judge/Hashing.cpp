#include <bits/stdc++.h>
using namespace std;

/*
   Approach: OutDegree, Indegree

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 212 ms faster than: 70.23%
   Memory Usage: 68.9 MB less than: 28.9%
   Remarks:
*/

class Solution {
   public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> out(n, 0), in(n, 0);
        for (vector<int> itr : trust) {
            out[itr[0] - 1]++;
            in[itr[1] - 1]++;
        };
        for (int i = 0; i < n; i++) {
            if (out[i] == 0 && in[i] == (n - 1)) return i + 1;
        }
        return -1;
    }
};