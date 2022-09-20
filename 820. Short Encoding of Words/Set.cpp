#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Hash set
    Remove duplicates


   Edge Cases:

   Time Complexity: O(n*m) Space: O(n)
   Status: Accepted
   Runtime: 313 ms faster than: 14.63%
   Memory Usage: 18.4 MB less than: 61.28%
   Remarks:
*/

class Solution {
   public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string> s(words.begin(), words.end());
        for (string itr : s) {
            for (int i = 1; i < itr.size(); i++) {
                s.erase(itr.substr(i));
            }
        }
        int len = 0;
        for (string itr : s) {
            len += itr.size() + 1;
        }
        return len;
    }
};