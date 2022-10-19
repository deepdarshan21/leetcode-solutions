#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Map and Priority queue

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 20 ms faster than: 61.52%
   Memory Usage: 8.4 MB less than: 77.90%
   Remarks:
*/

class Solution {
   public:
    string frequencySort(string s) {
        unordered_map<char, int> ump;
        for (char x : s) {
            ump[x]++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto itr : ump) {
            pq.push({itr.second, itr.first});
        }
        string res = "";
        while (!pq.empty()) {
            char x = pq.top().second;
            for (int i = 0; i < pq.top().first; i++) {
                res += x;
            }
            pq.pop();
        }
        return res;
    }
};