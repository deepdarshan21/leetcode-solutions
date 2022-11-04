#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O(nlogn) Space: O(n)
   Status: Accepted
   Runtime: 742 ms faster than: 32.45%
   Memory Usage: 120.9 MB less than: 25.36%
   Remarks:
*/

class Solution {
   public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        multiset<pair<int, int>> m;
        stack<int> st;
        vector<int> res(n, -1);
        st.push(0);
        for (int i = 1; i < n; i++) {
            while (!m.empty() && nums[i] > m.begin()->first) {
                res[m.begin()->second] = nums[i];
                m.erase(m.begin());
            }
            while (!st.empty() && nums[st.top()] < nums[i]) {
                m.insert({nums[st.top()], st.top()});
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};