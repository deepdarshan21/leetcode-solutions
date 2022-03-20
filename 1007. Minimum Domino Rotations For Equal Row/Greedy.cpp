#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Greedy


   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 246 ms faster than: 20.82%
   Memory Usage: 111.5 MB less than: 94.45%
   Remarks:
*/

class Solution {
   public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int top = tops[0], bottom = bottoms[0];
        int swapTop, swapBottom;
        bool isPossible;
        int ans = -1;
        swapTop = swapBottom = 0;
        isPossible = true;
        for (int i = 0; i < tops.size(); i++) {
            if (tops[i] != top && bottoms[i] != top) {
                isPossible = false;
                break;
            } else if (tops[i] != top) {
                swapTop++;
            } else if (bottoms[i] != top) {
                swapBottom++;
            }
        }
        // cout << swapTop << ", " << swapBottom << endl;
        if (isPossible) {
            ans = min(swapTop, swapBottom);
        }
        swapTop = swapBottom = 0;
        isPossible = true;
        for (int i = 0; i < tops.size(); i++) {
            if (tops[i] != bottom && bottoms[i] != bottom) {
                isPossible = false;
                break;
            } else if (tops[i] != bottom) {
                swapTop++;
            } else if (bottoms[i] != bottom) {
                swapBottom++;
            }
        }
        if (isPossible) {
            ans = min(swapTop, swapBottom);
        }
        return ans;
    }
};