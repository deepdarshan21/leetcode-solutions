#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force
        Take a outer "for" loop for selecting the start element
        Inside that loop use another loop to find the largest possible substring after performing
        operation "k" times

   Edge Cases:
        1. If without doing operation we can form the max substring starting some index

   Time Complexity: O(n^2) Space: O(1)
   Status: Wrong answer
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks: This algo fails in case where we need to perform opperation on start index element.
*/

class Solution {
   public:
    int characterReplacement(string s, int k) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            int tempK = k;
            for (int j = i + 1; j < s.size(); j++) {
                if (s[j] != s[i]) {
                    if (tempK == 0) {
                        res = max(res, j - i);
                        break;
                    }
                    tempK--;
                }
                if (j == s.size() - 1) {
                    res = max(res, (int)s.size() - i);
                }
            }
        }
        return res;
    }
};