#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Recursion(dfs)

   Edge Cases:

   Time Complexity: O(2^n) Space: O(n)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 7.6 MB less than: 19%
   Remarks:
*/

class Solution {
   public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_map<string, bool> mp;
        for (string word : wordDict) mp[word] = true;

        vector<string> res;
        function<void(string, string, int)> dfs = [&](string curr, string ans, int idx) {
            if (idx == n) {
                if (curr != "") return;
                ans.erase(ans.begin());
                res.push_back(ans);
                return;
            }
            curr += s[idx];
            if (mp[curr]) {
                dfs("", ans + " " + curr, idx + 1);
            }
            dfs(curr, ans, idx + 1);
        };

        dfs("", "", 0);

        return res;
    }
};