#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP

   Edge Cases:

   Time Complexity: O(n*2) Space: O(n)
   Status: Accepted
   Runtime: 941 ms faster than: 47%
   Memory Usage: 15 MB less than: 51%
   Remarks:
*/

class Solution {
   public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int, int> idx;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            idx[arr[i]] = i;
        }
        int res = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((idx[i] + idx[j]) >= 0) {
                    int k = idx[idx[i] + idx[j]];
                    mp[j * n + k] = mp[i * n + 1] + 1;
                    res = max(res, mp[j * n + k]);
                }
            }
        }
        return res >= 3 ? res : 0;
    }
};