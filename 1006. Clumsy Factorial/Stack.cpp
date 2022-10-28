#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Stack based math solution

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 5.9 MB less than: 78.35%
   Remarks:
*/

class Solution {
   public:
    int clumsy(int n) {
        int res = 0, opr = n - 1, temp = n, i = 0;
        while (--n) {
            if (i % 4 == 0)
                temp *= n;
            else if (i % 4 == 1)
                temp /= n;
            else if (i % 4 == 2) {
                res += temp + n;
                temp = 0;
            } else
                temp = -1 * n;
            // cout<<n<<" "<<i<<" "<<temp<<" "<<res<<endl;
            i++;
        }
        res += temp;
        return res;
    }
};