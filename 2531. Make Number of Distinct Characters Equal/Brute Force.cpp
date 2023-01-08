#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 294 ms faster than: 7.41%
   Memory Usage: 62.4 MB less than: 7.41%
   Remarks:
*/

class Solution {
   public:
    bool isItPossible(string word1, string word2) {
        unordered_map<char, int> mp1, mp2;
        for (char word : word1) mp1[word]++;
        for (char word : word2) mp2[word]++;
        auto isSameDistint = [&](unordered_map<char, int> mp1, unordered_map<char, int> mp2) {
            int count1 = 0, count2 = 0;
            for (char i = 'a'; i <= 'z'; i++) {
                if (mp1[i] > 0) count1++;
                if (mp2[i] > 0) count2++;
            }
            if (count1 == count2) return true;
            return false;
        };
        for (char i = 'a'; i <= 'z'; i++) {
            if (mp1[i] == 0) continue;
            for (int j = 'a'; j <= 'z'; j++) {
                if (mp2[j] == 0) continue;
                mp1[i]--;
                mp1[j]++;
                mp2[j]--;
                mp2[i]++;
                if (isSameDistint(mp1, mp2)) return true;
                mp1[j]--;
                mp1[i]++;
                mp2[i]--;
                mp2[j]++;
            }
        }
        return false;
    }
};