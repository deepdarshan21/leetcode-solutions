#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Greedy


   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 10 ms faster than: 21.93%
   Memory Usage: 6.8 MB less than: 24.05%
   Remarks:
*/

class Solution {
   public:
    vector<int> partitionLabels(string s) {
        map<char, int> mp;
        for (int i = 0; i < s.length(); i++) {
            mp[s[i]] = i;
        }
        vector<int> res;
        int count = 0, breakOn = 0;
        for (int i = 0; i < s.length(); i++) {
            count++;
            breakOn = max(breakOn, mp[s[i]]);
            if (i == breakOn) {
                res.push_back(count);
                count = 0;
            }
        }
        return res;
    }
};