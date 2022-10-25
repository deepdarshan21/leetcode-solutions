#include <bits/stdc++.h>
using namespace std;

/*
   Approach:

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 177 ms faster than: 39.01%
   Memory Usage: 16.4 MB less than: 70.89%
   Remarks:
*/

class Solution {
   public:
    int countCollisions(string directions) {
        int n = directions.size();
        int left = 0, right = n - 1;
        while (left < n && directions[left] == 'L') left++;
        while (right >= 0 && directions[right] == 'R') right--;
        int res = 0;
        for (int i = left; i <= right; i++) {
            if (directions[i] != 'S') res++;
        }
        return res;
    }
};