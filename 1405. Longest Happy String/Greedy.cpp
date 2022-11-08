#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Priority Queue

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 6.1 MB less than: 45.12%
   Remarks:
*/

class Solution {
   public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        pq.push({a, 'a'});
        pq.push({b, 'b'});
        pq.push({c, 'c'});
        string res = "";
        while (pq.top().first > 0) {
            pair<int, char> p1, p2;
            p1 = pq.top();
            pq.pop();
            p2 = pq.top();
            pq.pop();
            // cout<<p1.second<<" "<<p1.first<<endl;
            // cout<<p2.second<<" "<<p2.first<<endl;
            // if (p1.first == 0 || p2.first == 0) break;
            if (p1.first == p2.first && p1.first > 1) {
                if (res.back() != p1.second) {
                    res += p1.second;
                    res += p1.second;
                    p1.first -= 2;
                    res += p2.second;
                    res += p2.second;
                    p2.first -= 2;
                } else {
                    res += p2.second;
                    res += p2.second;
                    p2.first -= 2;
                    res += p1.second;
                    res += p1.second;
                    p1.first -= 2;
                }
            } else {
                if (p1.first > 0) {
                    res += p1.second;
                    p1.first--;
                    if (p1.first > 0) {
                        res += p1.second;
                        p1.first--;
                    }
                }
                if (p2.first > 0) {
                    res += p2.second;
                    p2.first--;
                }
            }
            pq.push(p1);
            pq.push(p2);
            // cout<<res<<endl;
        }
        for (int i = 2; i < res.size(); i++) {
            if (res[i] == res[i - 1] && res[i] == res[i - 2]) {
                res = res.substr(0, i);
                break;
            }
        }
        return res;
    }
};