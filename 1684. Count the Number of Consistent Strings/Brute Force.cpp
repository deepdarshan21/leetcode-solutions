#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accpeted
   Runtime: 63 ms faster than: 91.26%
   Memory Usage: 30.3 MB less than: 27.61%
   Remarks:
*/

class Solution {
   public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, int> ump;
        for (char x : allowed) {
            ump[x]++;
        }
        int count = 0;
        bool isAllOkay;
        for (string word : words) {
            isAllOkay = true;
            for (char x : word) {
                if (ump[x] == 0) {
                    isAllOkay = false;
                    break;
                }
            }
            if (isAllOkay) count++;
        }
        return count;
    }
};