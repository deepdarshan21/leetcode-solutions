#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Stack

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 92 ms faster than: 21.32%
   Memory Usage: 23.8 MB less than: 91.19%
   Remarks:
*/

class Solution {
   public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        stack<int> st;
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!st.empty() and st.top() <= nums[i % n]) st.pop();
            res[i % n] = st.empty() ? -1 : st.top();
            st.push(nums[i % n]);
        }
        return res;
    }
};