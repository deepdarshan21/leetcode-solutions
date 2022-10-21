#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Use Map to store lat occurence of any number

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 501 ms faster than: 14.45%
   Memory Usage: 76.9 MB less than: 82.38%
   Remarks:
*/

class Solution {
   public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if (mp[nums[i]] != 0) {
                int temp = i + 1 - mp[nums[i]];
                if (temp <= k) return true;
            }
            mp[nums[i]] = i + 1;
        }
        return false;
    }
};