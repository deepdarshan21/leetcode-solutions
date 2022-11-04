#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Two Pointer

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 14 ms faster than: 59.67%
   Memory Usage: 7.7 MB less than: 61.66%
   Remarks:
*/

class Solution {
   public:
    string reverseVowels(string s) {
        int n = s.size(), low = 0, high = n - 1;
        string vowel = "aeiouAEIOU";
        while (low < high) {
            while (low < n && find(vowel.begin(), vowel.end(), s[low]) == vowel.end()) low++;
            while (high >= 0 && find(vowel.begin(), vowel.end(), s[high]) == vowel.end()) high--;
            if (low < high) {
                swap(s[low], s[high]);
                low++;
                high--;
            }
        }
        return s;
    }
};