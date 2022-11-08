#include <bits/stdc++.h>
using namespace std;

/*
   Approach:First count the freq of letters and then with the help of priority queue place the highest
        freq letter first at alternate positions

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 6.4 MB less than: 35.85%
   Remarks:
*/

class Solution {
   public:
    string reorganizeString(string s) {
        if (s.size() == 1) return s;
        unordered_map<char, int> mp;
        for (char x : s) mp[x]++;
        if (mp.size() == 1) return "";
        priority_queue<pair<int, char>> pq;
        for (auto itr : mp) pq.push({itr.second, itr.first});
        string res = "";
        while (pq.top().first > 0) {
            pair<int, char> p1 = pq.top();
            pq.pop();
            res.push_back(p1.second);
            p1.first--;
            pair<int, char> p2 = pq.top();
            pq.pop();
            if (p2.first > 0) {
                res.push_back(p2.second);
                p2.first--;
            }
            pq.push(p1);
            pq.push(p2);
        }
        for (int i = 1; i < res.size(); i++) {
            if (res[i] == res[i - 1]) return "";
        }
        return res;
    }
};