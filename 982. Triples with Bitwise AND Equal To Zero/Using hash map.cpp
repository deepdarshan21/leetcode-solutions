#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O(n^3) Space: O(n^2)
   Status: Accepted
   Runtime: 765 ms faster than: 17.50%
   Memory Usage: 12.9 MB less than: 37.50%
   Remarks:
*/

class Solution {
   public:
    int countTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> store;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                store[nums[i] & nums[j]]++;
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (auto& [key, val] : store) {
                if ((key & nums[i]) == 0) res += val;
            }
        }
        return res;
    }
};