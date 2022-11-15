#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Greedy

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Accepted
   Runtime: 148 ms faster than: 71.59%
   Memory Usage: 22.5 MB less than: 69.77%
   Remarks:
*/

class Solution {
   public:
    int findLongestChain(vector<vector<int>> &pairs) {
        if (pairs.size() == 0) return 0;
        sort(pairs.begin(), pairs.end(), [](vector<int> &first, vector<int> &second) {
            return first[1] < second[1];
        });
        int last = 0, res = 0, n = pairs.size();
        for (int i = 1; i < n; i++) {
            if (pairs[last][1] >= pairs[i][0])
                res++;
            else
                last = i;
        }
        return n - res;
    }
};