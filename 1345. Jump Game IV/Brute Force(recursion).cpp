#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Wrong Answer
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        auto rec = [&](auto&& rec, int i) -> int {
            if (i >= n - 1) return 0;
            int ans = INT_MAX;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] == arr[i]) {
                    ans = min(ans, 1 + rec(rec, j));
                }
            }
            if (i < n) ans = min(ans, 1 + rec(rec, i + 1));
            if (i > 0) ans = min(ans, 1 + rec(rec, i - 1));
            return ans;
        };
        return 1 + rec(rec, 0);
    }
};