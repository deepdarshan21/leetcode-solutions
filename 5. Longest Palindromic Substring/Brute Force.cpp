#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force

   Edge Cases:

   Time Complexity: O(n^3) Space: O(1)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    string longestPalindrome(string s) {
        int n = s.size();
        int max = INT_MIN;
        string maxString;
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                string newString, reverseString;
                newString = s.substr(i, len);
                reverseString = newString;
                reverse(reverseString.begin(), reverseString.end());
                if (newString.compare(reverseString) == 0) {
                    int temp = reverseString.size();
                    if (max < temp) {
                        max = reverseString.size();
                        maxString = reverseString;
                    }
                }
            }
        }
        cout << max;
        return maxString;
    }
};