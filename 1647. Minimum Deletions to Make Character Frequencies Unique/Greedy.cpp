#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Greedy
        Sort the freq of elements

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 56 ms faster than: 92.62%
   Memory Usage: 17.2 MB less than: 95.01%
   Remarks:
*/

class Solution {
   public:
    int minDeletions(string s) {
        vector<int> mp(26, 0);
        for (char c : s) mp[c - 97]++;
        sort(mp.begin(), mp.end(), greater<int>());
        int del = 0;
        for (int i = 1; i < 26; i++) {
            if (mp[i] < mp[i - 1] || mp[i] == 0) continue;
            if (mp[i] >= mp[i - 1]) {
                int temp = mp[i];
                mp[i] = max(0, mp[i - 1] - 1);
                del += temp - mp[i];
            }
        }
        return del;
    }
};