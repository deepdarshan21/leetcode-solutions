#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Wrong Answer
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks: Not playing the game optimally
*/

class Solution {
   public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        bool isAliceWin = false, isTie = false;

        auto rec = [&](auto rec, int i, int alice, int bob, int turn) -> void {
            if (i >= n) {
                if (alice > bob)
                    isAliceWin = true;
                else if (alice == bob)
                    isTie = true;
                return;
            }
            if (turn == 0) {
                rec(rec, i + 1, alice + stoneValue[i], bob, 1);
                if (i + 1 < n) rec(rec, i + 2, alice + stoneValue[i] + stoneValue[i + 1], bob, 1);
                if (i + 2 < n) rec(rec, i + 3, alice + stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2], bob, 1);
            } else {
                rec(rec, i + 1, alice, bob + stoneValue[i], 0);
                if (i + 1 < n) rec(rec, i + 2, alice, bob + stoneValue[i] + stoneValue[i + 1], 0);
                if (i + 2 < n) rec(rec, i + 3, alice, bob + stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2], 0);
            }
        };

        rec(rec, 0, 0, 0, 0);
        if (isAliceWin)
            return "Alice";
        else if (isTie)
            return "Tie";
        else
            return "Bob";
    }
};