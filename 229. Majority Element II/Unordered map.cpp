#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Unordered map

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 32 ms faster than: 39.91%
   Memory Usage: 16 MB less than: 9.97%
   Remarks:
*/

class Solution {
   public:
    vector<int> majorityElement(vector<int>& nums) {
        int freq = nums.size() / 3;
        unordered_map<int, int> mp;
        for (int num : nums) mp[num]++;
        vector<int> res;
        for (auto itr : mp)
            if (itr.second > freq) res.push_back(itr.first);
        return res;
    }
};