#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DFS

   Edge Cases:

   Time Complexity: O(n*n) Space: O(n*n)
   Status: Accepted
   Runtime: 850 ms faster than: 47.43%
   Memory Usage: 277.6 MB less than: 6.36%
   Remarks: Its the first time when I solved hard problem in one go without any help😃
*/

class Solution {
   public:
    int longestPath(vector<int>& parent, string s) {
        unordered_map<int, vector<int>> gh;
        int n = parent.size(), res = 0;
        auto dfs = [&](auto dfs, int i) {
            cout << i << " " << s[i] << endl;
            if (gh[i].size() == 0) {
                res = max(res, 1);
                cout << 1 << endl;
                return 1;
            }
            cout << "check" << endl;
            int tmp1 = 0, tmp2 = 0;
            // tmp1 for max for parent
            // tmp2 for sum for own
            for (int j = 0; j < gh[i].size(); j++) {
                cout << "gh[i][j]: " << gh[i][j] << endl;
                if (s[i] == s[gh[i][j]]) {
                    dfs(dfs, gh[i][j]);
                } else {
                    int tmp = dfs(dfs, gh[i][j]);
                    cout << "tmp: " << tmp << endl;
                    if (tmp1 < tmp) {
                        tmp2 = tmp1;
                        tmp1 = tmp;
                    } else if (tmp2 < tmp && tmp1 >= tmp) {
                        tmp2 = tmp;
                    }
                }
                cout << "res: " << res << ", tmp1: " << tmp1 << ", tmp2: " << tmp1 + tmp2 << endl;
            }
            res = max(res, tmp1 + 1);
            res = max(res, tmp1 + tmp2 + 1);
            return tmp1 + 1;
        };
        for (int i = 1; i < n; i++) gh[parent[i]].push_back(i);
        dfs(dfs, 0);
        // res = max(res, tmp);
        return res;
    }
};