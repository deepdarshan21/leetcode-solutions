#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Greedy

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(n)
   Status: Accepted
   Runtime: 343 ms faster than: 65.40%
   Memory Usage: 62.5 MB less than: 79.49%
   Remarks:
*/

class Solution {
   public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for (int x : arr) mp[x]++;
        vector<int> store;
        for (auto itr : mp) store.push_back(itr.second);
        sort(store.begin(), store.end());
        int res = store.size();
        int i = 0;
        while (k != 0 && i < store.size()) {
            if (k >= store[i]) {
                res--;
                k -= store[i];
            } else
                break;
            i++;
        }
        return res;
    }
};