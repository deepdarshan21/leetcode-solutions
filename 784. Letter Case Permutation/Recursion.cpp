#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Recursion

   Edge Cases:

   Time Complexity: O(n^n) Space: O(n)
   Status: Accepted
   Runtime: 1149 ms faster than: 5.14%
   Memory Usage: 20 MB less than: 5.10%
   Remarks:
*/

class Solution {
   public:
    vector<string> letterCasePermutation(string s) {
        set<string> res;
        int n = s.size();
        help(s, 0, n, res);
        return vector<string>(res.begin(), res.end());
    }

   private:
    void help(string s, int idx, int &n, set<string> &res) {
        // cout<<idx<<endl;
        for (int i = idx; i < n; i++) {
            if (isdigit(s[i])) continue;
            s[i] = tolower(s[i]);
            help(s, i + 1, n, res);
            s[i] = toupper(s[i]);
            help(s, i + 1, n, res);
        }
        // cout<<s<<endl;
        res.insert(s);
    }
};