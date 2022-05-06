#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Using stack
        Use stack to store the element visited and pop k element if top k elements are same


   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 63 ms faster than: 19.63%
   Memory Usage: 10 MB less than: 80.87%
   Remarks:
*/

class Solution {
   public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> store;
        int i = 0;
        store.push({s[i], 1});
        i++;
        while (i < s.size()) {
            while (!store.empty() && store.top().second == k) {
                store.pop();
            }
            if (!store.empty() && store.top().first == s[i]) {
                store.top().second++;
            } else {
                store.push({s[i], 1});
            }
            i++;
        }
        if (!store.empty() && store.top().second == k) {
            store.pop();
        }
        string res = "";
        while (!store.empty()) {
            while (store.top().second > 0) {
                res += store.top().first;
                store.top().second--;
            }
            store.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};