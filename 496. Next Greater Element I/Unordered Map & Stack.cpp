#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Using unordered map and stack
        ~Use map for hashing nums2, so that we can find the index of certain element of nums1 in nums2
        ~using stack and a vector of size nums.size() to store the next maximum element to element at that
        index

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n)
   Status: Accepted
   Runtime: 6 ms faster than: 77.24%
   Memory Usage: 9 MB less than: 33.42%
   Remarks:
*/

class Solution {
   public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> store;
        for (int i = 0; i < nums2.size(); i++) {
            store[nums2[i]] = i;
        }
        stack<int> st;
        vector<int> res(nums2.size());
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() && nums2[i] >= st.top()) {
                st.pop();
            }
            res[i] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }
        vector<int> ans;
        for (auto num1 : nums1) {
            ans.push_back(res[store[num1]]);
        }
        return ans;
    }
};