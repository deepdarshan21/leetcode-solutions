#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status:
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    vector<int> countBits(int n) {
        vector<int> ans;
        int noOf1 = 0, temp;
        for (int i = 0; i <= n; i++) {
            noOf1 = 0;
            temp = i;
            while (temp != 0) {
                noOf1++;
                temp &= (temp - 1);
            }
            ans.push_back(noOf1);
        }
        return ans;
    }
};