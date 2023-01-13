#include <bits/stdc++.h>
using namespace std;

/*
   Approach:BFS

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 451 ms faster than: 38.30%
   Memory Usage: 51.6 MB less than: 35.21%
   Remarks:
*/

class Solution {
   public:
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") return 0;
        unordered_map<string, bool> dead;
        for (string deadeand : deadends) dead[deadeand] = true;
        queue<string> q, tmpQ;
        set<string> vis;
        auto upDown = [&](char ch, bool up) {
            if (ch == '0' && !up) return '9';
            if (ch == '9' && up) return '0';
            if (up) return (char)(ch + 1);
            return (char)(ch - 1);
        };
        if (dead["0000"]) return -1;
        q.push("0000");
        vis.insert("0000");
        int res = 0;
        while (!q.empty()) {
            res++;
            while (!q.empty()) {
                string tmp = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    char ch = tmp[i];
                    tmp[i] = upDown(ch, true);
                    if (tmp == target) return res;
                    if (vis.find(tmp) == vis.end() && !dead[tmp]) {
                        tmpQ.push(tmp);
                        vis.insert(tmp);
                    }
                    tmp[i] = upDown(ch, false);
                    if (tmp == target) return res;
                    if (vis.find(tmp) == vis.end() && !dead[tmp]) {
                        tmpQ.push(tmp);
                        vis.insert(tmp);
                    }
                    tmp[i] = ch;
                }
            }
            swap(q, tmpQ);
        }
        return -1;
    }
};