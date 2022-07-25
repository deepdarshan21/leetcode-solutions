#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Recursion
        First compare the last char of both string and if char match then return one plus the lcs
        of string without those char. If char not match then return the max lcs of string1 and string2
        without last char and string1 without last char and string2

   Edge Cases:
    If any of the strings size 0 then size of lcs will be 0

   Time Complexity: O(2^n) Space: O(log(n))
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.size() == 0 || text2.size() == 0) {
            return 0;
        } else {
            if (text1[text1.size() - 1] == text2[text2.size() - 1]) {
                return 1 + longestCommonSubsequence(text1.substr(0, text1.size() - 1), text2.substr(0, text2.size() - 1));
            } else {
                return max(longestCommonSubsequence(text1.substr(0, text1.size()), text2.substr(0, text2.size() - 1)), longestCommonSubsequence(text1.substr(0, text1.size() - 1), text2.substr(0, text2.size())));
            }
        }
    }
};