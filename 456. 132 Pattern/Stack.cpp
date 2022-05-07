#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Stack
        Use stack for finding s3<s2 relationship

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 95 ms faster than: 54.76%
   Memory Usage: 38.2 MB less than: 68.61%
   Remarks:
*/

class Solution {
   public:
    bool find132pattern(vector<int>& nums) {
        stack<int> store;
        int third = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < third) {
                return true;
            }
            while (!store.empty() && nums[i] > store.top()) {
                third = store.top();
                store.pop();
            }
            store.push(nums[i]);
        }
        return false;
    }
};