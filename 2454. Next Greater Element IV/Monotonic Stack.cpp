#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O(n^2) Space: O(n)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> nextGreater(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                nextGreater[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        vector<int> res(n, -1);
        for (int i = 0; i < n; i++) {
            if (nextGreater[i] == -1) continue;
            int searchFrom = nextGreater[i] + 1;
            while (searchFrom < n && nums[searchFrom] <= nums[i]) searchFrom = nextGreater[searchFrom];
            if (searchFrom < n)
                res[i] = nums[searchFrom];
            else
                res[i] = -1;
        }
        return res;
    }
};