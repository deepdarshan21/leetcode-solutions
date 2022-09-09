#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Sorting


   Edge Cases:

   Time Complexity: O(n^2) Space: O(1)
   Status:Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end());

        int count = 0, n = properties.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (properties[i][1] < properties[j][1]) {
                    count++;
                    break;
                }
            }
        }

        return count;
    }
};