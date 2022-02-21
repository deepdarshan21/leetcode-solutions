#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force
        Take one element and count it's frequency

   Edge Cases:

   Time Complexity: O(n^2) Space: O(1)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int count = 0, ans;
        for (auto i : nums) {
            count = 0;
            for (auto j : nums) {
                if (i == j) {
                    count++;
                }
            }
            if (count > nums.size() / 2) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};