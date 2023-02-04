#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Use a map to store the frequency of each character in s1. Then, iterate

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks: It will take O(n^2) time complexity to check if s2 contains s1.
*/

class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if (n > m) return false;
        unordered_map<char, int> store;
        for (char c : s1) store[c]++;
        for (int i = 0; i < m; i++) {
            if (store.find(s2[i]) != store.end()) {
                unordered_map<char, int> temp = store;
                int j = i;
                while (j < m && temp.find(s2[j]) != temp.end()) {
                    temp[s2[j]]--;
                    if (temp[s2[j]] == 0) temp.erase(s2[j]);
                    j++;
                }
                if (temp.empty()) return true;
            }
        }
        return false;
    }
};