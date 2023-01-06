#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Set

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 199 ms faster than: 69.88%
   Memory Usage: 51.3 MB less than: 21.81%
   Remarks:
*/

class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        set<int> st;
        for (int i = 0; i < n; i++) st.insert(nums[i]);
        int tmp = 0, res = 0;
        for (int i : st) {
            if (st.find(i - 1) == st.end())
                tmp = 1;
            else
                tmp++;
            res = max(tmp, res);
        }
        return res;
    }
};