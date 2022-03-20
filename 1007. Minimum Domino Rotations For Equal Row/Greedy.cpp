#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Greedy
        Check to every possible value at top and bottom

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 336 ms faster than: 5.00%
   Memory Usage: 111.5 MB less than: 72.27%
   Remarks:
*/

class Solution {
   public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = INT_MAX, tempCount;
        bool runComplete;
        for (int up = 1; up <= 6; up++) {
            tempCount = 0;
            runComplete = true;
            for (int i = 0; i < tops.size(); i++) {
                if (tops[i] != up) {
                    if (bottoms[i] == up) {
                        tempCount++;
                    } else {
                        runComplete = false;
                        break;
                    }
                }
            }
            if (runComplete) {
                ans = min(ans, tempCount);
            }
        }

        for (int bottom = 1; bottom <= 6; bottom++) {
            tempCount = 0;
            runComplete = true;
            for (int i = 0; i < bottoms.size(); i++) {
                if (bottoms[i] != bottom) {
                    if (tops[i] == bottom) {
                        tempCount++;
                    } else {
                        runComplete = false;
                        break;
                    }
                }
            }
            if (runComplete) {
                ans = min(ans, tempCount);
            }
        }
        if (ans == INT_MAX) {
            return -1;
        }
        return ans;
    }
};