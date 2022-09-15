#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Use unordered map to store the freq of each char and check is there freq of 2*element is greater then equal to freq of element

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(n)
   Status: Accepted
   Runtime: 766 ms faster than: 40.60%
   Memory Usage: 146.4 MB less than: 37.30%
   Remarks:
*/

class Solution {
   public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if (n % 2 == 1) return {};
        unordered_map<int, int> mp;
        vector<int> res;
        for (int i = 0; i < n; i++) mp[changed[i]]++;
        vector<int> keys;
        for (auto itr : mp) keys.push_back(itr.first);
        sort(keys.begin(), keys.end());
        for (auto itr : keys) {
            int temp = itr;
            if (mp[temp] > mp[temp * 2]) return {};
            for (int i = 0; i < mp[temp]; i++, mp[temp * 2]--) res.push_back(temp);
        }
        return res;
    }
};