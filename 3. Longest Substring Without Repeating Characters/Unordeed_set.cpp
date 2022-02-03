#include <bits/stdc++.h>
using namespace std;

/*
    Approach: Nativ Approach using Unordered_set
       

   Edge Cases:
       1. size of string is 0

   Time Complexity: O(n^2) Space: O(n^2)
*/

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) {
            return 0;
        }
        int max = INT_MIN, temp;
        for (int i = 0; i < s.size(); i++) {
            unordered_set<char> S;
            S.insert(s[i]);
            for (int j = i + 1; j < s.size(); j++) {
                if (S.find(s[j]) != S.end()) {
                    break;
                }
                S.insert(s[j]);
            }
            int size = S.size();
            if (size > max) {
                max = S.size();
            }
            if (max == s.size()) {
                return max;
            }
        }
        return max;
    }
};
