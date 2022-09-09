#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force
        Check for every possible combination

   Edge Cases:

   Time Complexity: O(n^2) Space: O(1)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int count = 0;
        int n = properties.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (properties[i][0] < properties[j][0] && properties[i][1] < properties[j][1]) {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};