#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Map and Space

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 22 ms faster than: 76.50%
   Memory Usage: 15.4 MB less than: 7.93%
   Remarks:
*/

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int num : nums) {
            mp[num]++;
        }
        vector<vector<int>> freq(n + 1);
        for (auto itr : mp) {
            freq[itr.second].push_back(itr.first);
        }
        vector<int> res;
        int count = 0;
        for (int i = n; i >= 0; i--) {
            for (int itr : freq[i]) {
                count++;
                res.push_back(itr);
                if (count == k) break;
            }
            if (count == k) break;
        }
        return res;
    }
};