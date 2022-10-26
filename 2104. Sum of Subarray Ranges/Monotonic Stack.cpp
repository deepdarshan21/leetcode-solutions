#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Monotonic Stack + Memorization

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 27 ms faster than: 84.57%
   Memory Usage: 11 MB less than: 36.19%
   Remarks:
*/

class Solution {
   public:
    long long subArrayRanges(vector<int>& nums) {
        long long res = 0;
        int n = nums.size();
        vector<long long> dp(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            dp[i] = st.empty() ? (i + 1) * (long long)nums[i] : dp[st.top()] + (i - st.top()) * (long long)nums[i];
            res += dp[i];
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) st.pop();
            dp[i] = st.empty() ? (i + 1) * (long long)nums[i] : dp[st.top()] + (i - st.top()) * (long long)nums[i];
            res -= dp[i];
            st.push(i);
        }
        return res;
    }
};