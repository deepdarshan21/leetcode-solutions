#include <bits/stdc++.h>
using namespace std;

/*
    Approach: SLiding Window and Hashing
       Store the last occurence of every char of string and check that selected
       char is less then the start of new substring.

   Edge Cases:
       1. String on size one.

   Time Complexity: O(n) Space: O(n)
*/

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_map<char, int> lastOccur;
        char temp;
        for (int start = 0, end = 0; end < s.size(); end++) {
            temp = s[end];
            if (lastOccur[temp] >= start) {
                start = lastOccur[temp];
            }
            lastOccur[temp] = end + 1;
            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};