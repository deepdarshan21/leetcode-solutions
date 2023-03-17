#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Recursion
        The game can be mapped to minmax game. Alice tries to maximize the total
        score and Bob tries to minimize it.

   Edge Cases:

   Time Complexity: O(3^n) Space: O(1)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        auto rec = [&](auto self, int idx, int turn) -> int {
            if (idx >= n) return 0;
            int score = 0, bestMax = INT_MIN, bestMin = INT_MAX;
            for (int i = 0; i < 3 && idx + i < n; i++) {
                if (turn == 0) {
                    score += stoneValue[idx + i];
                    bestMax = max(bestMax, score + self(self, idx + i + 1, 1 - turn));
                } else {
                    score -= stoneValue[idx + i];
                    bestMin = min(bestMin, score + self(self, idx + i + 1, 1 - turn));
                }
            }
            return turn == 0 ? bestMax : bestMin;
        };

        int tmp = rec(rec, 0, 0);
        if (tmp > 0)
            return "Alice";
        else if (tmp == 0)
            return "Tie";
        else
            return "Bob";
    }
};