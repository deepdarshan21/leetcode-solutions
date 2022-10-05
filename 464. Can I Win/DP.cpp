#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Wrong answer
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    bool canIWin(int maxChoosableInteger, int desiredTotal, int minChoosableInteger = 1, int player = 1) {
        if (desiredTotal <= maxChoosableInteger)
            if (player == 1)
                return true;
            else
                return false;
        return canIWin(maxChoosableInteger - 1, desiredTotal - maxChoosableInteger, minChoosableInteger, player == 1 ? 2 : 1) || canIWin(maxChoosableInteger, desiredTotal - minChoosableInteger, minChoosableInteger + 1, player == 1 ? 2 : 1);
    }
};