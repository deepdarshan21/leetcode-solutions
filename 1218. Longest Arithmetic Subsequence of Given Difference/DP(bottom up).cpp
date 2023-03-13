#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP(bottom up)
        Use a map to store the longest subsequence ending at each element.
        The longest subsequence ending at arr[i] is the longest subsequence ending at [arr[i] - difference] + 1.
        The answer is the maximum value in the map.

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 129 ms faster than: 96.51%
   Memory Usage: 56.6 MB less than: 39.61%
   Remarks:
*/

class Solution {
   public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        unordered_map<int, int> dp;

        for (int i = 0; i < n; i++) dp[arr[i]] = dp[arr[i] - difference] + 1;
        int res = 0;
        for (auto i : dp) res = max(res, i.second);
        return res;
    }
};