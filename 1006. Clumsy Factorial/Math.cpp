#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Math(Brute Force)


   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Wrong Answer
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int clumsy(int n) {
        int res = n, opr = n;
        n--;
        for (int i = 0; i < opr - 1; i++) {
            if ((opr % 4) == 0)
                res *= n;
            else if ((opr % 4) == 1)
                res /= n;
            else if ((opr % 4) == 2)
                res += n;
            else if ((opr % 4) == 3)
                res -= n;
            n--;
        }
        return res;
    }
};