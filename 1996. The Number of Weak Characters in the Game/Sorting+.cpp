#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Wrong answer
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks: Fail for test case where maxAttack's defence is much small
*/

class Solution {
   public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end());

        int maxAttack = INT_MIN, maxDefence = INT_MIN;
        int n = properties.size();
        maxAttack = properties[n - 1][0];
        maxDefence = properties[n - 1][1];
        // for (int i = 0; i < n; i++) {
        //     if (maxAttack < properties[i][0]) {
        //         maxAttack = properties[i][0];
        //         maxDefence = properties[i][1];
        //     } else {
        //         if (maxDefence < properties[i][1]) {
        //             maxDefence = properties[i][1];
        //         }
        //     }
        // }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (properties[i][0] < maxAttack && properties[i][1] < maxDefence) {
                count++;
            }
        }
        return count;
    }
};