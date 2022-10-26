#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Monotonic Stack + DP
        Use help of previous calculation

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 96 ms faster than: 96.49%
   Memory Usage: 40.9 MB less than: 83.58%
   Remarks:
*/

class Solution {
   public:
    int sumSubarrayMins(vector<int>& arr) {
        int res = 0, n = arr.size(), mod = 1e9 + 7;
        vector<int> dp(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            dp[i] = st.empty() ? (i + 1) * arr[i] : dp[st.top()] + (i - st.top()) * arr[i];
            st.push(i);
        }
        for (int i = 0; i < n; i++) {
            res = (res + dp[i]) % mod;
        }
        return res;
    }
};