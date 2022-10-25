#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Unordered map + stack


   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 318 ms faster than: 57.25%
   Memory Usage: 29.8 MB less than: 62.86%
   Remarks:
*/

class Solution {
   public:
    string robotWithString(string s) {
        stack<char> t;
        string res = "";
        char toFound = 'a';
        unordered_map<char, int> mp;
        int n = s.size();
        for (char x : s) mp[x]++;
        for (char x : s) {
            t.push(x);
            mp[x]--;
            // cout<<t.top()<<" "<<toFound<<endl;
            while (!t.empty() && toFound <= 'z') {
                // cout<<"Top: "<<t.top()<<endl;
                // while (toFound<='z' &&mp[toFound] == 0) toFound++;
                // cout<<"Found: "<<toFound<<endl;
                while (!t.empty()) {
                    if (t.top() <= toFound) {
                        res += t.top();
                        // mp[t.top()]--;
                        t.pop();
                    } else
                        break;
                }
                while (toFound <= 'z' && mp[toFound] == 0) toFound++;
                if (t.empty() || t.top() > toFound) break;
            }
            // mp[x]--;
        }
        while (!t.empty()) {
            res += t.top();
            t.pop();
        }
        return res;
    }
};