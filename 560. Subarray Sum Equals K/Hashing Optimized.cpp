#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Hashing
        Store the sum with its freq in unordered map and find if "sum-k" exists in map or not,
        if exits than add its freq.

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 96 ms faster than: 68.27%
   Memory Usage: 38.3 MB less than: 39.16%
   Remarks:
*/

class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        map<int, int> mp;
        int sum = 0;
        mp[sum] = 1;
        for (auto num : nums) {
            sum += num;
            if (mp.find(sum - k) != mp.end()) {
                count += mp[sum - k];
            }
            mp[sum]++;
        }
        return count;
    }
};