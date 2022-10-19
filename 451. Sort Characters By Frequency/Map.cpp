#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Map and space

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 35 ms faster than: 19.94%
   Memory Usage: 13.9 MB less than: 6.32%
   Remarks:
*/

class Solution {
   public:
    string frequencySort(string s) {
        unordered_map<char, int> ump;
        for (char x : s) {
            ump[x]++;
        }
        int n = s.size();
        vector<vector<char>> freq(n);
        for (auto itr : ump) {
            freq[itr.second - 1].push_back(itr.first);
        }
        string res = "";
        for (int i = n - 1; i >= 0; i--) {
            if (freq[i].size() == 0) continue;
            // cout<<i;
            for (char x : freq[i]) {
                // cout<<"  "<<x<<" "<<endl;
                for (int j = 0; j < (i + 1); j++)
                    res += x;
            }
        }
        return res;
    }
};