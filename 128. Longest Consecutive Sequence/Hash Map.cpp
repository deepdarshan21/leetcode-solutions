#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Using Hashmap

   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks: Running loop from max element to min element can be expensive
*/

class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int minEle = INT_MAX, maxEle = INT_MIN;
        for (int i = 0; i < n; i++) {
            minEle = min(minEle, nums[i]);
            maxEle = max(maxEle, nums[i]);
            mp[nums[i]]++;
        }
        int tmp = 0, res = 0;
        for (int i = minEle; i <= maxEle; i++) {
            if (mp[i] == 0)
                tmp = 0;
            else
                tmp++;
            res = max(res, tmp);
        }
        return res;
    }
};