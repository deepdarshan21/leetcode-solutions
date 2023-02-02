#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Math

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 6.1 MB less than: 6.45%
   Remarks:
*/

class Solution {
   public:
    string convertToTitle(int columnNumber) {
        unordered_map<int, char> store;
        for (int i = 1; i <= 26; i++) store[i] = 'A' + i - 1;
        string ans = "";
        while (columnNumber > 0) {
            int rem = columnNumber % 26;
            if (rem == 0) {
                ans += 'Z';
                columnNumber = columnNumber / 26 - 1;
            } else {
                ans += store[rem];
                columnNumber /= 26;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};