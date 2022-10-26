#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Monotonic Stack

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 322 ms faster than: 8.23%
   Memory Usage: 42.7 MB less than: 69.09%
   Remarks:
*/

class Solution {
   public:
    int sumSubarrayMins(vector<int>& arr) {
        int res = 0, n = arr.size(), mod = 1e9 + 7;
        stack<int> st;
        vector<int> g1(n), g2(n);
        for (int i = n - 1; i >= 0; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            g2[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            g1[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        for (int i = 0; i < n; i++) {
            res = (res + (i - g1[i]) * (g2[i] - i) * (long long)arr[i]) % mod;
        }
        return res;
    }
};