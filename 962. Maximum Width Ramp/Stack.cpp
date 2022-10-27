#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Stack
    Store the smallest number from small as it will be my i and from end I will traverse fro every j

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 145 ms faster than: 27.80%
   Memory Usage: 29.3 MB less than: 83.18%
   Remarks:
*/

class Solution {
   public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> st;
        int res = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (st.empty() || nums[st.top()] > nums[i]) st.push(i);
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                res = max(res, abs(i - st.top()));
                st.pop();
            }
        }
        return res;
    }
};