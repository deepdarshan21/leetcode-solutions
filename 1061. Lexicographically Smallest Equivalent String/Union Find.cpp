#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Find Union

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 3 ms faster than: 79.82%
   Memory Usage: 6.6 MB less than: 60.55%
   Remarks:
*/

class Solution {
   public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        vector<char> par(26);
        auto findPar = [&](auto findPar, char ch) {
            int i = ch - 'a';
            if (par[i] == ch) return ch;
            return par[i] = findPar(findPar, par[i]);
        };
        auto unionCh1AndCh2 = [&](char ch1, char ch2) {
            char parCh1 = findPar(findPar, ch1);
            char parCh2 = findPar(findPar, ch2);
            if (parCh1 < parCh2) {
                par[parCh2 - 'a'] = parCh1;
            } else {
                par[parCh1 - 'a'] = parCh2;
            }
        };
        for (char i = 'a'; i <= 'z'; i++) par[i - 'a'] = i;
        for (int i = 0; i < n; i++) {
            unionCh1AndCh2(s1[i], s2[i]);
        };
        string res = "";
        for (char ch : baseStr) res += findPar(findPar, ch);
        return res;
    }
};