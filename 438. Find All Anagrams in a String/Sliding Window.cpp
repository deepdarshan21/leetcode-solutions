#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Sliding Window(same as 567. Permutation in String)

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 12 ms faster than: 84.91%
   Memory Usage: 8.7 MB less than: 77.40%
   Remarks:
*/

class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<int> res;
        if (n < m) return res;
        vector<int> sFreq(26, 0), pFreq(26, 0);
        for (int i = 0; i < m; i++) {
            sFreq[s[i] - 'a']++;
            pFreq[p[i] - 'a']++;
        }
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (sFreq[i] == pFreq[i]) count++;
        }
        for (int i = m; i < n; i++) {
            if (count == 26) res.push_back(i - m);
            int toRemove = s[i - m] - 'a';
            int toAdd = s[i] - 'a';
            sFreq[toRemove]--;
            if (sFreq[toRemove] == pFreq[toRemove])
                count++;
            else if (sFreq[toRemove] == pFreq[toRemove] - 1)
                count--;
            sFreq[toAdd]++;
            if (sFreq[toAdd] == pFreq[toAdd])
                count++;
            else if (sFreq[toAdd] == pFreq[toAdd] + 1)
                count--;
        }
        if (count == 26) res.push_back(n - m);
        return res;
    }
};