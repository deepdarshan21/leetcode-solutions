#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O(n^2logn) Space: O(1)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        int n = words.size();
        string temp, rev_temp;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                rev_temp = temp = words[i] + words[j];
                reverse(rev_temp.begin(), rev_temp.end());
                if (temp == rev_temp) res.push_back({i, j});
                rev_temp = temp = words[j] + words[i];
                reverse(rev_temp.begin(), rev_temp.end());
                if (temp == rev_temp) res.push_back({j, i});
            }
        }
        return res;
    }
};