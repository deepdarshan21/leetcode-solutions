#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Backtrack

   Edge Cases:

   Time Complexity: O(2^n) Space: O(n)
   Status: Accepted
   Runtime: 653 ms faster than: 53.85%
   Memory Usage: 39.6 MB less than: 23.8%
   Remarks:
*/

class Solution {
   public:
    int beautifulSubsets(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> vis(1001, 0);
        auto backtrack = [&](auto self, int idx) {
            if (idx == n) return 1;
            int take = 0, notTake = 0;
            if (arr[idx] - k < 0 || vis[arr[idx] - k] == 0) {
                vis[arr[idx]]++;
                take = self(self, idx + 1);
                vis[arr[idx]]--;
            }
            notTake = self(self, idx + 1);
            return take + notTake;
        };
        return backtrack(backtrack, 0) - 1;
    }
};