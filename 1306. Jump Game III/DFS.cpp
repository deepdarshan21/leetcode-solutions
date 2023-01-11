#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DFS

   Edge Cases:

   Time Complexity: O(n) Space: O(log(n))
   Status: Accepted
   Runtime: 50 ms faster than: 73.58%
   Memory Usage: 44.7 MB less than: 12.62%
   Remarks:
*/

class Solution {
   public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        auto dfs = [&](auto dfs, int start) {
            if (start < 0 || start >= n || arr[start] == -1) return false;
            if (arr[start] == 0) return true;
            int tmp = arr[start];
            arr[start] = -1;
            if (dfs(dfs, start + tmp)) return true;
            if (dfs(dfs, start - tmp)) return true;
            return false;
        };
        return dfs(dfs, start);
    }
};