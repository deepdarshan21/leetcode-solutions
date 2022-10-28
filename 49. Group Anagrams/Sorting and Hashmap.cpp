#include <bits/stdc++.h>
using namespace std;

/*
   Approach: make a copy, sort every element, use map to store the freq using sorted vector<string>

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(n)
   Status: Accepted
   Runtime: 85 ms faster than: 37.34%
   Memory Usage: 20.7 MB less than: 41.59%
   Remarks:
*/

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> copy(strs.begin(), strs.end());
        int n = strs.size();
        for (int i = 0; i < n; i++) sort(copy[i].begin(), copy[i].end());
        unordered_map<string, vector<int>> ump;
        for (int i = 0; i < n; i++) ump[copy[i]].push_back(i);
        vector<vector<string>> res;
        for (auto itr : ump) {
            res.push_back({});
            for (int idx : itr.second) res.back().push_back(strs[idx]);
        }
        return res;
    }
};