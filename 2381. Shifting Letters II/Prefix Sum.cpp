#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Prefix Sum
        Mark the start and end of each shift, and the direction of the shift.
        Then, we can use prefix sum to calculate the total shift of each
        position. Finally, we can use the total shift to calculate the new
        position of each character.

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 349 ms faster than: 84.80%
   Memory Usage: 93.2 MB less than: 76.10%
   Remarks:
*/

class Solution {
   public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        int m = shifts.size();
        vector<int> tmp(n + 1, 0);
        for (int i = 0; i < m; i++) {
            if (shifts[i][2] == 0) {
                tmp[shifts[i][0]]--;
                tmp[shifts[i][1] + 1]++;
            } else {
                tmp[shifts[i][0]]++;
                tmp[shifts[i][1] + 1]--;
            }
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += tmp[i];
            int temp = sum % 26;
            int pos = (s[i] - 'a' + temp + 26) % 26;
            s[i] = 'a' + pos;
        }
        return s;
    }
};