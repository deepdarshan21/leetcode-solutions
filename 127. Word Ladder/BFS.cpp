#include <bits/stdc++.h>
using namespace std;

/*
   Approach: BFS

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 659 ms faster than: 33.36%
   Memory Usage: 149 MB less than: 5.4%
   Remarks:
*/

class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, bool> list;
        for (string word : wordList) list[word] = true;
        if (!list[endWord]) return 0;
        queue<string> q, tmpQ;
        unordered_map<string, bool> vis;
        q.push(beginWord);
        vis[beginWord] = true;
        int res = 0;
        while (!q.empty()) {
            res++;
            while (!q.empty()) {
                string tmp = q.front();
                q.pop();
                for (int i = 0; i < tmp.size(); i++) {
                    char ch = tmp[i];
                    for (char i = 'a'; i <= 'z'; i++) {
                        if (i == ch) continue;
                        tmp[i] = i;
                        if (tmp == endWord) return res + 1;
                        if (list[tmp] && !vis[tmp]) {
                            tmpQ.push(tmp);
                            vis[tmp] = true;
                        }
                    }
                    tmp[i] = ch;
                }
            }
            swap(q, tmpQ);
        }
        return 0;
    }
};