#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Unordered Map and Sorting

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(n)
   Status: Accepted
   Runtime: 40 ms faster than: 23.35%
   Memory Usage: 13.7 MB less than: 73.33%
   Remarks:
*/

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }
        vector<pair<int, int>> temp;
        for (auto itr : mp) {
            temp.push_back({itr.second, itr.first});
        }
        sort(temp.begin(), temp.end(), greater<pair<int, int>>());
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(temp[i].second);
        }
        return res;
    }
};