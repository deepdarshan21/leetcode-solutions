#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Stack

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 238 ms faster than: 74.95%
   Memory Usage: 107.6 MB less than: 6.10%
   Remarks:
*/

class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        int n = temps.size();
        vector<int> res(n);
        stack<pair<int, int>> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top().first < temps[i]) {
                res[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push({temps[i], i});
        }
        while (!st.empty()) {
            res[st.top().second] = 0;
            st.pop();
        }
        return res;
    }
};