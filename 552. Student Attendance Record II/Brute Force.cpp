#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force
        Check all possible combinations of P, L, A

   Edge Cases:

   Time Complexity: O(3^n) Space: O(n)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int checkRecord(int n) {
        int mod = 1e9 + 7;
        int res = 0;
        int freqA = 0;
        vector<char> record;

        auto rec = [&](auto rec, int i) -> void {
            if (freqA >= 2) return;
            if (i > 2 && record[i - 3] == 'L' && record[i - 1] == 'L' && record[i - 2] == 'L') return;
            if (i == n) {
                res++;
                res %= mod;
                return;
            }

            // P
            record.push_back('P');
            rec(rec, i + 1);
            record.pop_back();

            // L
            record.push_back('L');
            rec(rec, i + 1);
            record.pop_back();

            // A
            freqA++;
            record.push_back('A');
            rec(rec, i + 1);
            record.pop_back();
            freqA--;
        };
        rec(rec, 0);
        return res;
    }
};