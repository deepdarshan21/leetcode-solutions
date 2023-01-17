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
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        auto dfs = [&](auto dfs, char last, int i) {
            if (i == n) return 0;
            int res = INT_MAX;
            if (last == '1') {
                res = dfs(dfs, '1', i + 1);
            } else {
                res = min(res, dfs(dfs, '0', i + 1));
                res = min(res, dfs(dfs, '1', i + 1));
            }
            if (s[i] != last) res++;
            return res;
        };
        return min(dfs(dfs, '0', 0), dfs(dfs, '1', 0));
    }
};