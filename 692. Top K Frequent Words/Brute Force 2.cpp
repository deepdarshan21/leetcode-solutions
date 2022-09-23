#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Sorting of map element by freq

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(n)
   Status: Accepted
   Runtime: 33 ms faster than: 15.18%
   Memory Usage: 12.8 MB less than: 38.78%
   Remarks:
*/

class Solution {
   public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mp;
        for (string word : words) mp[word]++;
        vector<pair<int, string>> store;
        for (auto itr : mp) {
            store.push_back({itr.second, itr.first});
        }
        sort(store.begin(), store.end(), [](pair<int, string> s1, pair<int, string> s2) {
            if (s1.first == s2.first)
                return s1.second < s2.second;
            return s1.first > s2.first;
        });
        vector<string> res;
        for (int i = 0; i < k; i++) {
            res.push_back(store[i].second);
        }
        return res;
    }
};