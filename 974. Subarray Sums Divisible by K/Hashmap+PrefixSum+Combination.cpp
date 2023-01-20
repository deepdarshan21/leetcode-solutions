#include <bits/stdc++.h>
using namespace std;

/*
   Approach: HashMap, Prefix Sum, Combinations

   Edge Cases:

   Time Complexity: O(n+k) Space: O(k*2)
   Status: Accepted
   Runtime: 92 ms faster than: 43.24%
   Memory Usage: 39.2 MB less than: 5.29%
   Remarks:
*/

class Solution {
   public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum = 0;
        mp[sum]++;
        for (int num : nums) {
            sum += num;
            mp[sum % k]++;
        };
        int res = 0;
        for (int i = 0; i < k; i++) {
            int tmp = mp[i] + mp[i - k];
            if (tmp < 2) continue;
            res += ((tmp * (tmp - 1)) / 2);
        }
        return res;
    }
};